#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;


//conversion
inline ll toInt(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}


int s(ll x){
  int res = 0;
  while(x!=0){
    res += x % 10;
    x /= 10;
  }
  return res;
}

double f(ll i){
  return (double)i/(double)(s(i));
}


ll f2(ll x){
  string s = toString(x);
  vector<pair<double,ll>> p;
  p.push_back(make_pair(f(toInt(s)),toInt(s)));
  for(int i = s.size()-1 ; i >= 0; i--){
    s[i] = '9';

    p.push_back(make_pair(f(toInt(s)),toInt(s)));
  }
  sort(all(p));
  
  return p[0].second ;
}



ll make(int digit, int n){
  string s = "";
  s += toString(digit);
  rep(i,n){
    s += "9";
  }
  return toInt(s);
}

int main(){
  ll k;
  cin >> k;
  VLL ans;
  ans.push_back(1);
  ll fNum = 1;

  rep(i,k){
    fNum = f2(fNum+1);
    ans.push_back(fNum);
  }
  rep(i,k){
    cout << ans[i] << endl;
  }
  return 0;
}
