#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a,int b){
  while(b!=0){
    int r=a%b;
    a=b;
    b=r;
  }
  return a;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  int ans=gcd(a.at(0),a.at(1));
  rep(i,n){
    ans=gcd(a.at(i),ans);
     
  }
  cout << ans;
}
  
  