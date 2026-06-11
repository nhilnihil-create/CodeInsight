#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>


using namespace std;
using ll = long long;


int main()
{
    string s;
    ll K;
    cin >> s;
    cin >> K;
    set<string> substrs;
    for (ll j = 1; j <= K && j <= s.length(); j++) {
        for (auto i = 0; i <= s.length() - j; i++) {
            string sub = s.substr(i, j);
            substrs.insert(sub);
        }
    }
    vector<string> tmp;
    for (auto t : substrs) {
        tmp.push_back(t);
    }

    sort(tmp.begin(), tmp.end());
    cout << tmp[K - 1] << endl;
}
