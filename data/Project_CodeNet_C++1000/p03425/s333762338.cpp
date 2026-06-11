#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0; i<(int)n; i++)
#define rep2(i,a,n) for(long long i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
const ll mod = 1e9+7;
int gcd(int a, int b){if(a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

ll N, M, K, H, W, L, R, X;
string S, T;

int main(){
  string march = "MARCH";
  cin >> N;
  map<char, ll> mp;
  rep(i, N){
    string s; cin >> s;
    rep(j,5){
      if(s[0]==march[j]){mp[s[0]]++; break;}
    }
  }
  ll ans = 0;
  int cnt = mp.size();
  if(cnt <= 2){ cout << 0 << endl; return 0;}
  else if(cnt >= 3){
    for(auto itr1 : mp){
      for(auto itr2 : mp){
        if(itr2 <= itr1) continue;
        for(auto itr3 : mp){
          if(itr3 <= itr2) continue;
          ans += itr1.second*itr2.second*itr3.second;
        }
      }
    }
    cout << ans << endl;
    return 0;
  }

  return 0;
}