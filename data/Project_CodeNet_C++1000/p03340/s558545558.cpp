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

int Syakutori(vector<long> &d, int n, int k){
  int len = 0;
  long tmp = 1;
  for(int s=0,t=0; t<n; t++){ //
    //tmp *= d.at(t);
    //tmp += d.at(t);
    while(tmp < k && s <= t){
      tmp /= d.at(s);
      s++;
    }
    len = max(len, t-s+1);
  }
  return len;
}


int main(){
  int n;
  cin >> n;
  vl a(n);
  rep(i,n) cin >> a.at(i);
  long sum = 0;
  long xsum = 0;
  long ans = 0;
  for(int s=0,t=0; t<n; t++){
    sum += a.at(t);
    xsum = (xsum ^ a.at(t));
    while(sum != xsum && s <= t){
      sum -= a.at(s);
      xsum = (xsum ^ a.at(s));
      s++;
    }
    ans += t-s+1;
  }
  cout << ans << endl;
}