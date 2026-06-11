#include <bits/stdc++.h>
#include <complex>
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

ll N,M,H,W,K,Q,A,B,C,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
const long double EPS = 1e-9;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;


int main() {
    cin>>N;
    ll num = (1LL << N);
    vec a(num);
    rep(i,num) cin>>a[i];
    a.push_back(-1); //a[num]で最小値に飛ぶ
    mat dp(num,vec(2,num));
    rep(i,num){
        if(i == 0){
            dp[0][0] = 0;
        }else{
            dp[i][0] = i;
            ll &n1 = dp[i][0], &n2 = dp[i][1];
            //for(int j = ((i - 1) & i); ; j = ((j - 1) & i)){
            rep(bit,18){
                if(((i>>bit)&1) == 0) continue;
                int j = i - (1LL<<bit);
                rep(k,2){
                    ll tp = dp[j][k];
                    if((tp == n1) || (tp == n2)) continue;
                    if(a[n1] <= a[tp]){
                        n2 = n1;
                        n1 = tp;
                    }else if(a[n2] < a[tp]){
                        n2 = tp;
                    }
                }
                if(j == 0) break;
            }
        }
    }
    ll ans = -1;
    reps(i,1,num){
        ans = max(ans, a[dp[i][0]] + a[dp[i][1]]);
        cout<<ans<<endl;
    }
}