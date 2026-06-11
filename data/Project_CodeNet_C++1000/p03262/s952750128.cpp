#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
  if(a%b==0)return b;
  else return gcd(b,a%b);
}
int main(){
  int n;cin>>n;
  int x_ini;cin>>x_ini;
  vector<int>x(n);
  int tmp;
  for(int i=0;i<n;i++){
    cin>>tmp;
    x.at(i)=abs(x_ini-tmp);
  }
  int d=x.at(0);
  for(int i=1;i<n;i++){
    d=gcd(x.at(i),d);
  }
  cout <<d<<endl;
}