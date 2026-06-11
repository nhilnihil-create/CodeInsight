#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int h,w,n;
    cin >> h >> w >> n;
    int r,c;
    cin >> r >> c;
    string s,t;
    cin >> s >> t;
    reverse(ALL(s));
    reverse(ALL(t));
    int L = 1, R = w, U = 1, D = h;
    for(int i = 0; i < n; i++){
        if(t[i] == 'L' && R < w) R++;
        else if(t[i] == 'R' && L > 1) L--;
        else if(t[i] == 'U' && D < h) D++;
        else if(t[i] == 'D' && U > 1) U--;
        if(s[i] == 'L') L++;
        else if(s[i] == 'R') R--;
        else if(s[i] == 'U') U++;
        else D--;
        if(L > R || U > D){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(U <= r && r <= D && L <= c && c <= R){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}