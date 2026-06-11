#include<bits/stdc++.h>
using namespace std;
int main(){
int N,H;
  cin>>N>>H;
  vector<int>A(N);
  vector<int>B(N);
  for(int i=0;i<N;i++){
  int a,b;
    cin>>a>>b;
    A.at(i)=a;
    B.at(i)=b;
  }sort(A.begin(),A.end());
  int Max=A.at(N-1);
  sort(B.begin(),B.end());
  auto itr=lower_bound(B.begin(),B.end(),A.at(N-1));
  int k=distance(B.begin(),itr);
  int ans=0;
  int sum=0;
  for(int i=0; ;i++){
  if(i<=N-k-1){
  sum+=B.at(N-1-i);if(H<=sum){ans=i+1; break;}
  }else{
  sum+=A.at(N-1);if(H<=sum){ans=i+1; break;}
  }
  }cout<<ans<<endl;
   return 0;
}