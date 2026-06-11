#include <bits/stdc++.h>
#define rep(i, n) for(int i=0;i<(int)(n);++i)
#define rep1(i, n) for(int i=1;i<=(int)(n);++i)
#define irep(i, a, n) for(int i=a;i<(int)(n);++i)
#define rrep(i, n) for(int i=(int)(n)-1;i>=0;--i)
#define rrep1(i, n) for(int i=(int)(n);i>=1;--i)
#define allrep(V, v) for(auto&& V:v)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
const int INF=1<<29;
const double EPS=1e-9;
using namespace std;


map<long long, long long> prime_factorization(long long n){
  map<long long, long long> factors;
  for(lint div=2; div*div <= n; ++div){
    if(n % div != 0) continue;
    int count = 0;
    while(n % div == 0){
      ++count;
      n /= div;
    }
    factors[div] = count;
  }
  if(n != 1) factors[n] = 1;
  return factors;
}

int main (void)
{
  lint n,p; cin>>n>>p;
  if(n==1){
    cout << p << endl;
    return 0;
  }
  map<lint,lint> factors = prime_factorization(p);
  lint ans=accumulate(all(factors), (lint)1, [n](lint sum, pair<lint,lint> f){return f.second>=n ? sum*pow(f.first,(f.second/n)) : sum;});
  cout << ans << endl;
  return 0;
}
