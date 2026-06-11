#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
#define all(v) v.begin(), v.end()

int main(){
  string S;
  cin >> S;
  ll a=0,b=0;
  rep(i,S.size()){
    if(S.at(i)=='0') a++;
    else b++;
  }
  cout << 2*min(a,b) << endl;
}