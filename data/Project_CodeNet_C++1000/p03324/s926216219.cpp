#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int d,n;cin>>d>>n;
  int ans=1;
  rep(i,d)ans*=100;
  if(n==100)n++;
  cout<<ans*n<<endl;
}