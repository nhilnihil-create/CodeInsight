#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;
 
signed main() {
    IOS;
    #ifdef LOCAL
        freopen("input.txt","r", stdin);
        freopen("output.txt","w",stdout);
    #endif
    string s;   cin >> s;
    int n = s.length();
    s = "$" + s;
    if(s[1] != '1' || s[n] != '0')
        return cout << -1, 0;
    for(int i = 1; i < n; i++){
        if(s[i] != s[n-i])
            return cout << -1, 0;    
    } 
    cout << 1 << " " << 2 << endl;
    int curp = 1;
    for(int i = 2; i < n; i++){
        if(s[i] == '1'){    
            cout << i+1 << " " << curp << endl;
            curp = i + 1;
        }
        else
            cout << i+1 << " " << curp << endl;

    }
    return 0;
}