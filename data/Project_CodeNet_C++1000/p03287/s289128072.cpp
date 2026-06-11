#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;


int main(){
  ll n, m;
  cin >> n >> m;
  ll box[110000];
  map<ll, ll> mp;
  mp[0] = 1;
  ll ans = 0;
  rep(i, n){
    ll a;
    cin >> a;
    a = a%m;
    box[i] = i == 0 ? a : (box[i-1] + a)%m;
    mp[box[i]]++;
  }
  for(pair<ll, ll> x : mp){
    ans += x.second * (x.second - 1)/2;
  }
  cout << ans <<endl;
}
  