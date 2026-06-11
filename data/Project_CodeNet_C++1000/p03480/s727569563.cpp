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

ll N,M,H,W,K,Q,A,B,C,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;


int main(){
    cin>>S;
    N = S.size();
    ll lb = (N+1)/2, ub = N+1;
    while(ub - lb > 1){
        ll cen = (ub + lb)/2;
        bool ok = true;
        char c = S[N - cen];
        reps(i, N - cen, cen){
            if(c != S[i]) ok = false;
        }
        (ok ? lb : ub) = cen;
    }
    cout<<lb<<endl;
}