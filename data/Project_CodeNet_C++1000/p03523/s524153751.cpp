#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 101;
int pref[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s;
    cin >> s;
    string t;
    for (char c : s)
        if (c != 'A')
            t += c;
    if (t != "KIHBR") {
        cout << "NO" << endl;
        exit(0);
    }   
    vector <int> p;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] != 'A')
            p.app(i);
    for (int i = 0; i < s.size(); ++i)
        pref[i + 1] = pref[i] + (s[i] == 'A');
    if (pref[p[0]] > 1 || pref[p[1]] - pref[p[0]] > 0 || pref[p[2]] - pref[p[1]] > 0 || pref[p[3]] - pref[p[2]] > 1 || pref[p[4]] - pref[p[3]] > 1 || pref[s.size()] - pref[p[4]] > 1) {
        cout << "NO";
    }   
    else {
        cout << "YES";
    }   
    cout << endl;
}   