#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
//#define int long long

signed main(){
    string s; cin >> s;
    rep(i,3) if(s[i]=='1') s[i] = '0';
    rep(i,3) if(s[i]=='9') s[i] = '1';
    rep(i,3) if(s[i]=='0') s[i] = '9';
    cout << s << endl;
}