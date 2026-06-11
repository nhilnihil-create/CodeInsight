#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double PI=3.1415926535897932;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod

ll ans[60][3];
int main(){
    ll L; cin>>L;
    ll N=0;
    ll X=1;
    while(true){
        if(X>L) break;
        X*=2; N++;
    }
    ll i=0;
    cout<<N<<' ';
    while(true){
        if(L==1) break;
        if(L%2) {
            ans[i][0]=1;
            ans[i][1]=N;
            ans[i][2]=L-1;
            L--; i++;
        }
        else{
            ll K=L/2;
            ans[i][0]=N-1;
            ans[i][1]=N;
            ans[i][2]=K;
            i++;
            ans[i][0]=N-1;
            ans[i][1]=N;
            ans[i][2]=0;
            N--; L=K; i++;
        }
    }
    cout<<i<<endl;
    rep(j,i) cout<<ans[j][0]<<' '<<ans[j][1]<<' '<<ans[j][2]<<endl;
}