#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  double nm=0;
  vector<double>x(n);
  vector<string>u(n);
  for(int i=0;i<n;i++){
    cin>>x[i]>>u[i];
  }
  for(int i=0;i<n;i++){
    if(u[i]=="BTC"){
      nm+=x[i]*380000;
    }
    else{
      nm+=x[i];
    }
  }
  cout<<fixed<<setprecision(20)<<nm<<endl;
}