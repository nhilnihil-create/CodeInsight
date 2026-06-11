#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()


int N;
vector<long> value;

void update(int i){
  i += N-1;
  while(i > 0){
    i = (i-1)/2;
    long c1 = value.at(i*2 + 1);
    long c2 = value.at(i*2 + 2);
    value.at(i) = max(c1, c2);
  }
}

long query(int a, int b, int k, int l, int r){
  if(r <= a || b <= l) return 0;
  if(a <= l && r <= b) return value.at(k);
  else{
    long c1 = query(a, b, 2*k+1, l, (l+r)/2);
    long c2 = query(a, b, 2*k+2, (l+r)/2, r);
    return max(c1, c2);
  }
}

int main(){
  int n;
  cin >> n;
  N = 1;
  while (N < n) N *= 2; // 葉の数を計算（n以上の最小の2冪数）
  value = vector<long>(2 * N - 1, 0);

  vi h(n);
  vl a(n);
  rep(i,n) cin >> h[i];
  rep(i,n) cin >> a[i];


  rep(i,n){
    long t = h[i];
    value[N-1 + t-1] = query(0,t,0,0,N) + a[i];
    update(t-1);
  }
  cout << query(0,n,0,0,N) << endl;
}