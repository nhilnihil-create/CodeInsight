#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n; cin >> n;
    vi b(n), ans;
    rep(i, n) cin >> b[i];
    
    // 逆順に考える。添え字と番号が一致する最右のものを取り除く
    for(ll i=0; i<n; i++){
        bool chk = false;
        for(ll pos=b.size()-1; pos>=0; pos--){
            if(pos == b[pos]-1){
                ans.push_back(pos+1);
                b.erase(b.begin()+pos);
                chk = true;
                break;
            }
        }
        if(!chk){
            cout << -1 << endl;
            return 0;
        }
    }
    for(ll i=ans.size()-1; i>=0; i--) cout << ans[i] << endl;
}