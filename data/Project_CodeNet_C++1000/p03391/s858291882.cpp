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
const ll MOD = 998244353;
const ll INF = 1LL << 61;
const long double EPS = 1e-9;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main(){
    cin>>N;
    bool same = true;
    ll mini = INF, sum = 0;
    rep(i,N){
        cin>>A>>B;
        if(A != B) same = false;
        sum += A;
        if(A > B){
            mini = min(B,mini);
        }
    }
    cout<<(same ? 0 : sum - mini)<<endl;
}