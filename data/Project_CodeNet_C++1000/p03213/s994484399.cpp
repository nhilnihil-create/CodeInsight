#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<ld> vld;
typedef vector<string> vstr;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define endl "\n"

ll INF = 1e9;
ll MOD = 1000000007;
ll LINF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "YES" << endl;}
void no(){ cout << "NO" << endl;}

//-----------------------------------------
vector<long long> factor_array(long long n){
  vector<long long> res;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0){
      res.push_back(i);
      if(i*i!=n){
        res.push_back(n/i);
      }
    }
  }
  sort(res.begin(),res.end());
  return res;
}

bool is_prime(long long n){
  if(n==2){
    return true;
  }
  else if(n<2 || n%2==0){
    return false;
  }
  else{
    long long i = 3;
    while(i*i<=n){
      if(n%i==0){
        return false;
      }
      i += 2;
    }
    return true;
  }
}

vector<pair<long long, long long>> prime_factorization(long long n){
  vector<pair<long long, long long>> res ;
  vector<long long> tmp = factor_array(n) ;
  for(long long i = 0; i<(long long)tmp.size(); i++){
    if(is_prime(tmp[i])){
      long long m = n;
      long long cnt = 0;
      while(m%tmp[i]==0){
        m /= tmp[i];
        cnt++;
      }
      res.push_back(make_pair(tmp[i],cnt));
    }
  }
  return res;
}

vector<bool> prime_table(int n){
  vector<bool> res(n+1,true);

  res[0] = false;
  res[1] = false;

  for(int i=2;i*i<=n;i++){
    if(res[i]){
      int j = i+i;
      while(j<=n){
        res[j] = false;
        j += i;
      }
    }
  }
  return res;
}
//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll n;
  cin >> n;

  vll cnt(101,0);

  for(ll i = 2; i <= n; i++){
    vpll tmp = prime_factorization(i);
    ll sz = tmp.size();
    for(ll j = 0; j < sz; j++){
      cnt[tmp[j].first] += tmp[j].second;
    }
  }

  vll p2, p4, p14, p24, p74;

  for(ll i = 2; i <= n; i++){
    if(cnt[i] >= 24){
      p24.push_back(i);
    }
    if(cnt[i] >= 14){
      p14.push_back(i);
    }
    if(cnt[i] >= 4){
      p4.push_back(i);
    }
    if(cnt[i] >= 2){
      p2.push_back(i);
    }
  }

  ll m2 = p2.size();
  ll m4 = p4.size();
  ll m14 = p14.size();
  ll m24 = p24.size();

  ll ans = 0;

  for(ll i = 0; i < m4; i++){
    for(ll j = 0; j < m4; j++){
      for(ll k = 0; k < m2; k++){
        if(p4[i] != p4[j] && p4[j] != p2[k] && p2[k] != p4[i]) ans++;
      }
    }
  }

  ans /= 2;

  for(ll i = 1; i <= n; i++){
    if(cnt[i] >= 74) ans++;
  }

  for(ll i = 0; i < m24; i++){
    for(ll j = 0; j < m2; j++){
      if(p24[i] != p2[j]) ans++;
    }
  }

  for(ll i = 0; i < m14; i++){
    for(ll j = 0; j < m4; j++){
      if(p14[i] != p4[j]) ans++;
    }
  }

  cout << ans <<endl;



  return 0;
}

