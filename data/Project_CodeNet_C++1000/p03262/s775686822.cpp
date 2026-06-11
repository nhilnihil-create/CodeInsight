#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  ll n,x;
  cin >> n >> x;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i,n){
     cin >> a.at(i);
     b.at(i)=abs(x-a.at(i));
  }
  ll ans=b.at(0);
  rep(i,n){
     ans=__gcd(ans,b.at(i));
  }
  cout << ans << endl;
}
    