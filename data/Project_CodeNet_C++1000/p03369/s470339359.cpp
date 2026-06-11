#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) (1 + (int)((a) - 1)/(int)(b))
//#define int long long

signed main(){
    string s; cin >> s;
    int price = 700;
    rep(i,3) if(s[i]=='o') price += 100;
    cout << price << endl;
}