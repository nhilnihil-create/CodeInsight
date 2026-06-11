#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  vector<double> a(n);
  double m=0;
  rep(i,n){
    cin>>a[i];
    m+=a[i];
  }
  m/=n;

  int ri=0;
  rep(i,n){
    if(abs(m-a[i]) < abs(m-a[ri]))ri=i;
  }

  cout<<ri;

  return 0;
}