#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;cin>>N;vector<int>A(N);vector<int>B(N);vector<int>C(N);
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N;i++){cin>>B[i];C[i]=A[i]-B[i];}
  int count=0;int ans=0;
  sort(C.begin(),C.end());
  for(int i=0;i<N;i++){
    if(C[i]>=0)break;
    ans++;
    count+=C[i];
  }
  for(int i=N-1;i>=0;i--){
    if(count>=0){cout<<ans<<endl;return 0;}
    ans++;
    count+=C[i];
  }
  cout<<-1<<endl;
}