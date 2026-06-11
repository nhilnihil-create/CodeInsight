#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n;
  cin >> n;
  vector<int>vec(n+1);
  for(int i = 1; i<=n;i++){
    auto p=prime_factorize(i);
    for(auto j:p){
      vec[j.first]+=j.second;
    }
  }
  ll res = 0;
  rep(i,n+1){
    if(vec[i]>=74)res++;
  }
  rep(i,n+1){
    rep(j,n+1){
      if(i==j)continue;
      if(vec[i]>=2 && vec[j]>=24)res++;
    }
  }
  rep(i,n+1){
    rep(j,n+1){
      if(i==j)continue;
      if(vec[i]>=4 && vec[j]>=14)res++;
    }
  }
  int num=0;
  rep(i,n+1){
    rep(j,n+1){
      rep(k,n+1){
        if(i==j || j==k || k==i)continue;
        if(vec[i]>=2 && vec[j]>=4 && vec[k]>=4)num++;
      }
    }
  }
  cout << res+num/2 << endl;
  return 0;
}
