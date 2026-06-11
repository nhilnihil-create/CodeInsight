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
  for(int i=0;i<N;i++)
    C.at(i)=B.at(i)-A.at(i);
  int64_t sum=0;
  for(int i=0;i<N;i++)
    sum+=C.at(i);
  int64_t need1=0;
  for(int i=0;i<N;i++){
  if(0<C.at(i)){
  need1+=(1+C.at(i))/2;
  }
  }if(need1<=sum)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  
   return 0;
}