#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  vector<int64_t>B(N);
  for(int i=0;i<N;i++)
    cin>>B.at(i);
  vector<int64_t>C(N);
  for(int i=0;i<N;i++){
  C.at(i)=A.at(i)-B.at(i);
  }vector<int64_t>P={};
  vector<int64_t>M={};
  for(int i=0;i<N;i++){
  if(0<=C.at(i))
    P.push_back(C.at(i));
    else
      M.push_back(C.at(i));
  }sort(P.begin(),P.end());
  reverse(P.begin(),P.end());
  int64_t p=P.size();
  int64_t m=M.size();
  int64_t sum1=0;
  int64_t sum2=0;
  for(int i=0;i<p;i++)
    sum1+=P.at(i);
  for(int i=0;i<m;i++)
    sum2+=M.at(i);
  if(sum1+sum2<0)
    cout<<-1<<endl;
  else{
  int ans=m;
    int64_t sum3=0;
    for(int i=0;i<p+1;i++){
      if(-sum2<=sum3){
      ans+=i; break;
      }sum3+=P.at(i);
    }cout<<ans<<endl;
  }
  return 0;
}