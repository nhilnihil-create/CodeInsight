#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<double> a(n);
  vector<string> b(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    cin>>b[i];
  }
  double sum=0.00000;
  for(int i=0;i<n;i++){
    if(b[i]=="JPY"){
      sum+=a[i];
    }
    else{
      sum+=a[i]*380000;
    }
  }
  cout<<sum<<setprecision(6)<<endl;
}