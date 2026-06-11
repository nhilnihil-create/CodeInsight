#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  int ans=0;
  rep(i,n){
    int a;
    cin>>a;
    while(a%2==0){
      a/=2;
      ans++;
    }
  }
  cout<<ans<<endl;
}