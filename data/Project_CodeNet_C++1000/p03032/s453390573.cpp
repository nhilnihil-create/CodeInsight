#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  int64_t ans=0;
  for(int i=0;i<=N;i++)
    for(int j=0;j<=N-i;j++){
    if(K<i+j)
      continue;
      else{
      set<int>S;
        int64_t a=0;
        for(int k=0;k<i;k++){S.insert(A.at(k)); a+=A.at(k);}
        for(int l=1;l<=j;l++){S.insert(A.at(N-l));a+=A.at(N-l);}
        int b=0;
        for(auto x:S){
        if(K-i-j-b<=0)break;
          else{if(x<=0)a-=x; b++;}
        }if(ans<=a)ans=a;
      
      }
    }cout<<ans<<endl;
  return 0;
}