#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define max0(a,b,c) max(max(a,b),c)
#define min0(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
using Graph = vector<vector<int>>;
typedef long long lint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<ull> ulvec;
typedef vector<double> dvec;
typedef vector<pair<int,int>> pvec;
typedef vector<pair<ll,ll>> plvec;
typedef vector<tuple<ll,ll,ll>> tvec;
typedef vector<string> svec;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    ll k;
    cin>>k;
    lvec a(k);
    rep(i,k) cin>>a[i];
    ll max_n=2,min_n=2;
    bool ok=true;
    if(a[k-1]!=2) ok=false;
    for(int i=k-1;i>0;i--){
        ll s=min_n/a[i],t=max_n/a[i];
        if(s*a[i]%a[i-1]==0) min_n=s*a[i];
        else min_n=s*a[i]+a[i-1]-s*a[i]%a[i-1];
        max_n=(t+1)*a[i]-1-((t+1)*a[i]-1)%a[i-1];
        if(max_n<min_n){
            ok=false;
            break;
        }
    }
    ll s=min_n/a[0],t=max_n/a[0];
    min_n=s*a[0];max_n=(t+1)*a[0]-1;
    if(max_n<min_n) ok=false;
    if(ok) cout<<min_n<<' '<<max_n<<endl;
    else cout<<-1<<endl;
}