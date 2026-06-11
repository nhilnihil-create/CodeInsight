#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t,a;
  cin>>n>>t>>a;
  vector<double> x(n);
  int p=0;
  for(int i=0;i<n;i++){
    int h;
    cin>>h;
    x.at(i)=abs(a-(t-0.006*h));
    p=(x.at(i)<x.at(p)?i:p);
  }
  cout<<p+1<<endl;
}