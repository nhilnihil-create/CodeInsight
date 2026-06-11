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
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;


int main() {
    cin>>N;
    vec a(N);
    rep(i,N) cin>>a[i];
    ll ma, mi;
    rep(i,N){
        if(a[i] == *max_element(a.begin(), a.end())) ma = i;
        if(a[i] == *min_element(a.begin(), a.end())) mi = i;
    }
    cout<<N*2 - 1<<endl;
    if(a[ma] > abs(a[mi])){
        rep(i,N) cout<<ma+1<<' '<<i+1<<endl;
        rep(i,N-1) cout<<i+1<<' '<<i+2<<endl;
    }else{
        rep(i,N) cout<<mi+1<<' '<<i+1<<endl;
        rep(i,N-1) cout<<N-i<<' '<<N-1-i<<endl;
    }
}