#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  int cnt1=1,cnt2=1;
  rep(i,n){
    int a;cin>>a;
    if(a%2==0)cnt2*=2;
    cnt1*=3;
  }
  cout<<cnt1-cnt2<<endl;
}