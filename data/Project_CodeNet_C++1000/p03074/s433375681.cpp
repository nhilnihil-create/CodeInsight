#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  ll n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<ll> zero;
  vector<ll> one;
  if(s[0]=='0'){
    one.push_back(0);
  }
  char b = 'n';
  ll num = 0;
  rep(i,n){
    if(s[i]==b){
      num++;
    }else if(b=='1'){
      one.push_back(num);
      num=1;
    }else if(b=='0'){
      zero.push_back(num);
      num=1;
    }else{
      num = 1;
    }
    b = s[i];
  }
  if(s[n-1]=='0'){
    one.push_back(0);
    zero.push_back(num);
  }else{
    one.push_back(num);
  }

  // cout << one.size() << endl;
  // cout << zero.size() << endl;
  ll ans = 0;
  if(k >= zero.size()){
    rep(i,zero.size()){
      ans += one[i];
      ans += zero[i];
    }
    ans += one[one.size()-1];
    cout << ans << endl;
  }else{
    ll res;
    rep(i,k){
      ans += one[i];
      ans += zero[i];
    }
    ans += one[k];
    res = ans;
    rep(i,zero.size()-k){
      res -= one[i];
      res -= zero[i];
      res += one[k+i+1];
      res += zero[k+i];
      ans = max(res,ans);
    }
    cout << ans << endl;
  }


  return 0;
}