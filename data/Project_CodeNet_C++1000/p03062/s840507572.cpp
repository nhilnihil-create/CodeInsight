#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n, cnt = 0;
  cin >> n;
  ll sum = 0;
  bool zero = false;
  vector<ll> a(n), b(n);
  rep(i,n) {
    cin >> a[i];
    b[i] = abs(a[i]);
    sum += b[i];
    if (a[i] < 0) cnt++;
    if (a[i] == 0) zero = true;
  }
  sort(all(b));
  if(cnt%2==0 || zero) cout << sum << endl;
  else cout << sum-2*abs(b[0]) << endl;

  return 0;
}