#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}//a,bの最大公約数(gcd)を求める
ll lcm(ll a,ll b){return abs(a*b)/gcd(a,b);}//a,bの最小公倍数(lcm)を求める
vector<ll> enum_div(ll n){vector<ll> ret;for(int i=1 ; i*i<=n ; i++){if(n%i == 0){ret.push_back(i);if(i!=1 && i*i!=n)ret.push_back(n/i);}}ret.push_back(n);return ret;}
//↑nの約数を求める
vector<bool> IsPrime; void sieve(size_t max){if(max+1 > IsPrime.size())IsPrime.resize(max+1,true);IsPrime[0] = false;IsPrime[1] = false;for(size_t i=2; i*i<=max; ++i)if(IsPrime[i])for(size_t j=2; i*j<=max; ++j)IsPrime[i*j] = false;}
//↑エラトステネスの篩で素数を求める
#define roundup(divisor,dividend) (divisor + (dividend - 1)) / dividend //切り上げ割り算
#define all(x) (x).begin(),(x).end() //xの初めから終わりまでのポインタ
#define size_t ll //size_tは自動でllに変換される
const int mod = 1000000007;
ll n,b=0,h=0,ans=1000000;
string s;
int main(){
  cin >> n >> s;
  for (size_t i = 0; i < n; i++) if(s[i] == '.')h++;
  for (size_t i = 0; i < n; i++) {
    ans = min(ans,b+h);
    if(s[i] == '#')b++;
    if(s[i] == '.')h--;
  }
  ans = min(ans,b+h);
  cout << ans << endl;
}
