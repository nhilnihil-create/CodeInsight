#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){ //for debug
    ll n = vec.size();
    cout << "------------------------------------\n" ;
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
    cout << "------------------------------------\n" ;
}

void pr2d(vector<vector<ll>> vec){ // for debug
    ll h = vec.size();
    ll w = vec.at(0).size();
    cout << "------------------------------------\n" ;
    rep(i,h){
        rep(j,w){
            cout << vec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
    cout << "------------------------------------\n" ;
}

int main(){
    ll n , kk ; cin >> n >> kk;
    vector<ll> v(n);
    rep(i,n) cin >> v.at(i);

    vector<vector<vector<ll>>> tbl(51,vector<vector<ll>>(51,vector<ll>(51,-LINF)));

    for(int i=0;i<=n;i++){ //i個宝石を取る 1ループ目
        for(int l=0;l<=i;l++){ //左からl個取り、 2ループ目
            ll r = i-l; //右からr=i-l取ることを考える
            vector<ll> juery(0);
            ll juerysum = 0;
            for(int k=0;k<l;k++){
                juery.push_back(v.at(k));
                juerysum+=v.at(k);
            }
            for(int k=n-1;k>=n-r;k--){
                juery.push_back(v.at(k));
                juerysum+=v.at(k);
            }
            sort(juery.begin(),juery.end());
            tbl.at(0).at(i).at(l) = juerysum;
            for(int j=1;j<=i;j++){ //j個返却することを考える
                tbl.at(j).at(i).at(l) = tbl.at(j-1).at(i).at(l) - juery.at(j-1);
            }
        }
    }
    ll ans = 0;
    for(int z = 0;z<=kk;z++){ //z回操作を行う場合を考える。zは最大kk回
        rep(i,51){
            rep(j,51){
                if(i+j==z){
                    rep(k,51) ans = max(ans,tbl[i][j][k]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
