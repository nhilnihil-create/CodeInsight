#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n;cin>>n;
  long double cnt=0;
  rep(i,n){
    double x;
    string u;
    cin>>x>>u;
    if(u=="JPY")x=x;
    else x=x/1*380000.0;
    cnt+=x;
  }
  cout<<cnt<<endl;
}
  