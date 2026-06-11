#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long n,k;
  cin >> n>>k;
  
  long ans=1;
  rep(i,k){
    ans*=n-i;
  }
  rep(i,k){
    ans/=i+1;
  }
  
  cout<<n-k+1<<endl;  
}

