#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;

signed main(){
    int N;cin>>N;
    vector<int>A(N);
    int sum=0;
    REP(i,N){
        cin>>A[i];
        A[i]-=(i+1);
        sum+=A[i];
    }
  	vector<int>C(N);C=A;
  	sort(C.begin(),C.end());
  	int z=C[N/2];
  	int y=C[N/2-1];
  	int ans1=0,ans2=0;
  	REP(i,N){
      	ans1+=abs(A[i]-z);
      	ans2+=abs(A[i]-y);
    }
    cout<<min(ans1,ans2)<<endl;
}
