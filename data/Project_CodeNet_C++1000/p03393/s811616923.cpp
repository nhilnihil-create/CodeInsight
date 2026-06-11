#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s;
    cin >> s;
    if (s.size() < 26) {
        for (char c = 'a'; c <= 'z'; ++c) {
            bool in = 0;
            for (char t : s)
                in |= t == c;
            if (!in) {
                cout << s << c << endl;
                exit(0);
            }   
        }   
    }   
    else {
        for (int i = (int)s.size() - 2; i >= 0; --i) {
            int pos = -1;
            for (int j  = i + 1; j < s.size(); ++j) {
                if (s[j] > s[i]) {
                    if (pos == -1 || s[j] < s[pos]) {
                        pos = j;
                    }           
                }   
            }   
            if (pos != -1) {
                swap(s[i], s[pos]);
                cout << s.substr(0, i + 1) << endl;
                exit(0);
            }   
        }
        cout << -1 << endl;
    }   
}