#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

string s;
ll n,q;
vector<char>t,d;

// index が条件を満たすかどうか
bool isOKleft(ll index) {
    ll now = index;
    rep(i,q){
        if(t[i]==s[now]){
            if(d[i]=='L'){
                now--;
            }
            else{
                now++;
            }
        }
        if(now<0){
            return false;
        }
        if(now>=n){
            return true;
        }
    }
    return true;
}
bool isOKright(ll index) {
    ll now = index;
    rep(i,q){
        if(t[i]==s[now]){
            if(d[i]=='L'){
                now--;
            }
            else{
                now++;
            }
        }
        if(now<0){
            return false;
        }
        if(now>=n){
            return true;
        }
    }
    return false;
}
// 汎用的な二分探索のテンプレ
int binary_search1() {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = n; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOKleft(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}
int binary_search2() {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = n; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOKright(mid)) ok = mid;
        else ng = mid;
    }
    return ng;
}

int main(){
    cin >> n >> q;
    cin >> s;
    t.resize(q);
    d.resize(q);
    rep(i,q){
        cin >> t[i] >> d[i];
    }
    cout << binary_search2() - binary_search1() + 1 << endl;
    return 0;
}
