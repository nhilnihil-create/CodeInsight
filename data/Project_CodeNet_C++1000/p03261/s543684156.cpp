#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<string> ss;
    string prev;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        ss.insert(s);
        if(ss.count(s) == 2 ||
         ((prev[prev.size() - 1] != s[0]) && i != 0)){
            cout << "No";
            return 0;
        }
        prev = s;
    }
    cout << "Yes";
    return 0;
}