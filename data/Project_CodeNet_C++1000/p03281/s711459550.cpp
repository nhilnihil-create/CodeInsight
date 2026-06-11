#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
#define rep2(i, n, m) for(int i=(int)n; i<=(int)m; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<ll> vl;
const ll inf=1LL << 60;
const ll MOD=1000000007;

vector<int> enum_divisors(int n){
  vector<int> r;
  for(int i=1; i*i<=n; i++){
    if(n%i==0){
      r.push_back(i);
      if(n%i!=i)r.push_back(n/i);
    }
  }
  sort(r.begin(), r.end());
  return r;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int ans=0;
  rep1(i, n){
    if(i%2==1){
      vi a;
      a=enum_divisors(i);
      if(a.size()==8)ans++;
    }
  }

  cout << ans << endl;

  return 0;
}