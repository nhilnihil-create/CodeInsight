#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll gcd(ll a, ll b) {
  if(a < b) return gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}
signed main(){
  ll t;
  ll a,b,c,d,g,v;
  cin >> t;
  for(int i=0;i<t;i++){
    string ans;
    cin >> a >> b >> c >> d;
    if(b>a||(b<=a&&b>d)){
      ans = "No";
    }else if((b<=a&&b<=d)&&c>=b){
      ans ="Yes";
    }else{
      g = gcd(b,d);
      v = b-g+(a%g);
      if(v<=c){
        ans = "Yes";
      }else{
        ans = "No";
      }
    }
    cout << ans << endl;
  }
}