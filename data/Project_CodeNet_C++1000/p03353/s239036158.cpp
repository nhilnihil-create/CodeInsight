#include <algorithm>
#include <iostream>
#include <set>
#include <vector>   
using namespace std;


int main() {
    int k;
    string s;
    cin >> s >> k;
    int n = s.length();
    set<string> s_set;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; ++j) {
            s_set.insert(s.substr(i, j));
        }
    }
    vector<string> s_vec(s_set.begin(), s_set.end());
    sort(s_vec.begin(), s_vec.end());

    cout << s_vec[k - 1] << endl;
}