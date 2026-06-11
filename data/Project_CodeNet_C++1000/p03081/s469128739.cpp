#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
const int INF = 1e18;

signed main(){
    int n,q; cin >> n >> q;
    string s; cin >> s;
    char t[q], d[q];
    REP(i,q)  cin >> t[i] >> d[i];
    int ok = n;
    int ng = -1;
    int mid;
    while(ok - ng > 1){
        mid = (ok+ng)/2;
        int loc = mid;
        bool flg = false;
        REP(i,q){
            if(loc == -1) break;
            if(loc == n){
                flg = true;
                break;
            }
            if(t[i] == s[loc]){
                if(d[i] == 'R') loc++;
                else loc--;
                if(loc == n){
                    flg = true;
                    break;
                }
                if(loc == -1) break;
            }
        }
        if(flg) ok = mid;
        else ng = mid;
    }
    int ok2 = -1;
    int ng2 = n;
    int mid2;
    while(ng2 - ok2 > 1){
        mid2 = (ok2+ng2)/2;
        int loc = mid2;
        bool flg = false;
        REP(i,q){
            if(loc == n) break;
            if(loc == -1){
                flg = true;
                break;
            }
            if(t[i] == s[loc]){
                if(d[i] == 'R') loc++;
                else loc--;
                if(loc == n) break;
                if(loc == -1){
                    flg = true;
                    break;
                }
            }
        }
        if(flg) ok2 = mid2;
        else ng2 = mid2;
    }
    cout << max(n - (n-ok) - (ok2+1),0ll) << endl; 
}