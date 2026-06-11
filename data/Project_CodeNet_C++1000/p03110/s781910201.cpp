#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  double s=0;
  for(int i=0;i<n;i++){
    double x;
    string u;
    cin>>x>>u;
    s+=(u=="JPY"?x:380000*x);
  }
  cout<<fixed<<setprecision(10)<<s<<endl;
}