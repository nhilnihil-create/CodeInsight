#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    string t; cin >> t;
    int n = s.size();
    map<char, char> mps, mpt;
    for (int i = 0; i < n; ++i) {
        if (mps.count(s[i]) == 0) mps[s[i]] = t[i];
        else if (mps[s[i]] != t[i]) {
            cout << "No\n";
            return 0;
        }
        
        if (mpt.count(t[i]) == 0) mpt[t[i]] = s[i];
        else if (mpt[t[i]] != s[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}