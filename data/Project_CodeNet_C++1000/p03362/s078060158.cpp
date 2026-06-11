#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

bool isPrime(int x){
  if(x == 0 || x == 1) return false;
  for(int i = 2; i*i <= x; i++){
    if(x%i == 0) return false;
  }
  return true;
}

int main(void){
  int n;
  cin >> n;
  int i = 0;
  int m = 11;
  vector<int> a(n);
  while(i < n){
    if(isPrime(m)){
      a[i] = m;
      i++;
    }
    m += 5;
  }
  REP(j, n) printf("%d ", a[j]);
  printf("\n");
  return 0;
}