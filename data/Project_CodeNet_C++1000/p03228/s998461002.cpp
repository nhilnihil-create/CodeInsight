#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int a,b,k;
  
  cin >> a>>b>>k;
  int l=k/2;
  int n=k%2;
  while(l--){
    b+=a/2;
    a/=2;
    a+=b/2;
    b/=2;
  }
  while(n--){
    b+=a/2;
    a/=2;
  }
  cout<<a<<" "<<b<<endl;
}