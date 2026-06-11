#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,A[200100];
signed main(){
  cin>>N;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A[a]=i;
  }
  A[0]=N;
  A[N+1]=-1;
  int ans=0,cnt=0;
  for(int i=1;i<=N+1;i++){
    if(A[i]<A[i-1])ans=max(ans,cnt),cnt=1;
    else cnt++;
  }
  cout<<N-ans<<endl;
}