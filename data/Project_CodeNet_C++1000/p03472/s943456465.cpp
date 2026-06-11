#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
int main(){
    ll n,h;
    cin>>n>>h;
    vector<ll>B;
    ll ma=0;

    rep(i,n){
        ll a,b;
        cin>>a>>b;
        ma= max(ma,a);
        B.push_back(b);
    }
    sort(been(B),greater<ll>());
    ll ans =0;
    rep(i,n){
        if(B[i]<ma)break;
        h-=B[i];
        ans++;
        if(h<=0)break;
    }

    if(h>0)ans+=ceil((double)h/(double)ma);

    cout<<ans<<endl;
    
    }