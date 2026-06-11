#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=1e9;
const long long LINF=1e18;
#define int long long
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
//main
signed main(){
  int N,A,B;cin>>N>>A>>B;
  if(A*B<N)fin(-1);
  if(A+B>N+1)fin(-1);
  std::vector<int> ans(N);
  for(int i=0;i<A;i++)ans[i]=N-A+1+i;
  int res=N-(A+B-1);
  int now=A,mx=N-A;
  for(int i=1;i<B;i++){
    int p=min(res,A-1);
    for(int j=0;j<=p;j++)ans[now+j]=mx-p+j;
    mx-=p+1;now+=p+1;res-=p;
  }
  for(int i=0;i<N;i++)cout<<ans[i]<<" ";cout<<endl;
}
