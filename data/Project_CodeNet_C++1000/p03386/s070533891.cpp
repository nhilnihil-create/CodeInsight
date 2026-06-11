#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b,k;cin>>a>>b>>k;
  if(b-a+1>2*k){
    for(int i=a;i<a+k;i++)cout<<i<<endl;
    for(int i=b-k+1;i<=b;i++)cout<<i<<endl;
  }
  else {
    for(int i=a;i<=b;i++)cout<<i<<endl;
  }
}