#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define call(x) (x).cbegin(), (x).cend()
#define pb push_back
const double PI = acos(-1);
const int mod = 1e9+7;
const long long INF = (1LL << 60);
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  ll cnt = 0;
  for(ll i = 1; i < s.size(); i++){
    if(s[i] == '9') cnt++;
  }
  if(cnt == s.size()-1) cout << (s[0]-'0') + (s.size()-1)*9 << endl;
  else cout << (s[0]-'0'-1) + (s.size()-1)*9 << endl;
  return 0;
}