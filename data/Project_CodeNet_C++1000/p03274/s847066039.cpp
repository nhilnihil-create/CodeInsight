#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define _GLIBCXX_DEBUG
const int INF=1e18;

signed main(){
  	int N,K;cin>>N>>K;
    vector<int>A;
    vector<int>B;
  	A.pb(0);B.pb(0);
    REP(i,N){
        int a;cin>>a;
        if(a<0)A.pb(-a);
        if(a>0)B.pb(a);
        if(a==0)K--;
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int ans=INF;
    for(int i=0;i<A.size();i++){
      	for(int j=0;j<B.size();j++){
          	if(i+j!=K)continue;
          	int preans=(A[i]+B[j])+min(A[i],B[j]);
          	ans=min(ans,preans);
        }
    }
    cout<<ans<<endl;
}