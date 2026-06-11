#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VRSORT(v) sort(v.rbegin(), v.rend());//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define OUT(x) cout << x << endl
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

vector<pair<int64_t, int64_t> > prime_factorize(int64_t n) {
    vector<pair<int64_t, int64_t> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int64_t num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));//p^num
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main(){
  int64_t n,p;
  cin >> n>>p;
  if(n==1){
    cout << p << endl;
    return 0;
  }
  vector<pair<int64_t,int64_t>> res=prime_factorize(p);
  vector<int64_t> tmp;
  REP(i,res.size()){
    int64_t num= res[i].second / n;
    while(num>0){
      tmp.push_back(res[i].first);
      num--;
    }
  }
  int64_t ans=1;
  REP(i,tmp.size()){
    ans*=tmp[i];
  }
  if(p==1) cout << 1 << endl;
  else cout << ans << endl;
  return 0;
}