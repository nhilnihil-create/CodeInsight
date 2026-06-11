#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main(){
    cin>>A>>B;
    ll w = 626, b = 625;
    w -= A; b -= B;
    S = "";
    rep(i,100) S.push_back('.');
    vector<string> ans(100,S);
    rep(i,25){
        rep(j,25){
            ll l = i*4, u = j*4;
            rep(p,3) {
                ans[u+p][l] = ans[u+p][l+2] = '#';
                ans[u][l+p] = ans[u+2][l+p] = '#';
            }
            if(w > 0){
                --w;
                ans[u+2][l+1] = '.';
            }
            if(b > 0){
                if((j != 0) || (i != 24)) --b;
                if(j == 0){
                    ans[u][l+3] = '#';
                }else{
                    ans[u-1][l] = '#';
                }
            }
        }
    }
    cout<<"100 100"<<endl;
    rep(i,100){
        rep(j,100) cout<<ans[i][j];
        cout<<endl;
    }
}