#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,X,i,x,ans;
  cin >> n >> X;
  cin >> x;
  ans=abs(x-X);
  for(i=1;i<n;i++){
    cin >> x;
    ans=__gcd(ans,abs(x-X));
  }
  
  cout << ans << endl;
}