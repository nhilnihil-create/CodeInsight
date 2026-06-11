#include <bits/stdc++.h>
using namespace std;
#define null NULL
#define mp make_pair
#define pb(a) push_back(a)
#define sz(a) ((int)(a).size())
#define all(a) a.begin() , a.end()
#define fi first
#define se second
#define relaxMin(a , b) (a) = min((a),(b))
#define relaxMax(a , b) (a) = max((a),(b))
#define SQR(a) ((a)*(a))
#define PI 3.14159265358979323846
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

vi ToDigs(ll w){
  vi res;
  while(w > 0)
    res.pb(w % 10),
    w /= 10;
  reverse(all(res));
  return res;
}

ll FromDigs(const vi& d){
  ll res = 0;
  for(int i = 0;i < sz(d);++i)
    res = res * 10 + d[i];
  return res;
}

int Sum(ll w){
  int res = 0;
  for(int d : ToDigs(w)) res += d;
  return res;
}

bool Better(ll n, ll m){
  return n * Sum(m) > m * Sum(n);
}

ll GetNext(ll to){
  vi digs = ToDigs(to);

  vector<ll> cand = {to};
  for(int i = sz(digs) - 1;i >= 0;--i){
    digs[i] = 9;
    ll val = FromDigs(digs);
    if(val > to) cand.pb(val);
  }

  sort(all(cand));
  cand.erase(unique(all(cand)), cand.end());

  //for(ll e : cand) cout << e << endl;

  for(int i = 0;i < sz(cand);++i){
    bool fine = true;
    for(int j = i + 1;j < sz(cand);++j)
      if(Better(cand[i], cand[j])){
        fine = false;
        break;
      }
    if(fine) return cand[i];
  }
}

int main(){
  int k;
  scanf("%d", &k);

  ll val = 1;
  for(int i = 0;i < k;++i){
    printf("%lld\n", val);
    val = GetNext(val + 1);
  }

  return 0;
}
