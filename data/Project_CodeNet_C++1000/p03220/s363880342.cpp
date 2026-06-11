#include<iostream>
#include<vector>
using namespace std;
double temp(double H,double T){

  return T-(0.006*H);
}
int main(){

  int N;
  double T,A;
  cin>>N>>T>>A;
  vector<int>H(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>H[i];
  }
  int ans=0;
  double min=999999;
  for(int i=0;i<=N-1;i++){
  
    if(min>abs(A-temp(H[i],T))){
    
      min=abs(A-temp(H[i],T));
      ans=i+1;
    }
  }
  cout<<ans;
  return 0;
}