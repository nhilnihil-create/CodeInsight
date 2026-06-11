#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;

signed main(){
    int N;cin>>N;
    vector<int>A(N);
    int sum=0;
    REPS(i,N){
        int a;cin>>a;a-=i;
        A[i-1]=a;
        sum+=A[i-1];
    }
  	sort(A.begin(),A.end());
  	int d=A[N/2];
  	int e=A[N/2-1];
  	int ans=0,ans1=0;
    REP(i,N){
      	ans+=abs(A[i]-d);
      	ans1+=abs(A[i]-e);
    } 
    cout<<min(ans,ans1)<<endl;
}