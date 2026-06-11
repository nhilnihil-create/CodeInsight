#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  long long sum=0;
  vector<long long>A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    A.at(i)=A.at(i)-(i+1);
  }
  sort(A.begin(),A.end());
  long long b=0;
  if(N%2==1){
    if(N==1){
      b=A.at(0);
    }
    else{
      b=A.at(N/2);
    }
    for(int i=0;i<N;i++){
    sum=sum+abs(A.at(i)-b);
    }
  }
  else{
    b=(A.at(N/2)+A.at(N/2-1))/2;
    long long c=A.at(N/2);
    long long d=A.at(N/2-1);
    for(int i=0;i<N;i++){
    sum=sum+abs(A.at(i)-b);
    }
    long long sum2=0;
    long long sum3=0;
    for(int i=0;i<N;i++){
    sum2=sum2+abs(A.at(i)-c);
    }
    for(int i=0;i<N;i++){
    sum3=sum3+abs(A.at(i)-d);
    }
    sum=min(sum,min(sum3,sum2));
  }
  cout<<sum<<endl;
}
    
  
  
  
