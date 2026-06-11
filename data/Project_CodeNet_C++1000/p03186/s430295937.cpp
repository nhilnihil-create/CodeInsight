#include <bits/stdc++.h>
#define rep(i, a) for (ll i = 0; i < (a); ++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
#define reverse(v) reverse(v.begin(),v.end())
typedef long long ll;
typedef long double la;
using namespace std;
 
int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  if(a+b >= c){
    cout << b+c << endl;
    return 0;
  }else{
    cout << a+2*b+1 << endl;
    return 0;
  }
}