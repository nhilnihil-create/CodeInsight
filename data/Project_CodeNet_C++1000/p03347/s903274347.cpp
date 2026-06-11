#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  if(A.at(0)!=0)
    cout<<-1<<endl;
  else{
  bool x=true;
    for(int i=1;i<N;i++){
    if(2<=A.at(i)-A.at(i-1)){
      x=false; break;
    }
      }if(!x)
      cout<<-1<<endl;
    else{
     A.push_back(0);
      int64_t ans=0;
      int64_t sum=0;
      for(int i=1;i<=N;i++){
      if(A.at(i)-A.at(i-1)==1)
        sum++;
        else{ans+=sum; sum=A.at(i);}
      } cout<<ans<<endl;
    
    }
  
 }
   return 0;
}