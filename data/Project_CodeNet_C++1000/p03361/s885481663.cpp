#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define call(x) (x).cbegin(), (x).cend()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define sz(x) ((x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
const double PI = acos(-1);
const int mod = 1e9+7;
const long long INF = (1LL << 60);
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}
ll ceil(ll a, ll b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a=b; return 1; } return 0; }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  vector<vector<bool>> black(h, vector<bool>(w, false));
  rep(i, 0, h){
    rep(j, 0, w){
      if(s[i][j] == '.') continue;
      if(i != 0 && s[i-1][j] == '#') black[i-1][j] = true, black[i][j] = true;
      if(i != h-1 && s[i+1][j] == '#') black[i+1][j] = true, black[i][j] = true;
      if(j != 0 && s[i][j-1] == '#') black[i][j-1] = true, black[i][j] = true;
      if(j != w-1 && s[i][j+1] == '#') black[i][j+1] = true, black[i][j] = true;
    }
  }

  rep(i, 0, h){
    rep(j, 0, w){
      if(s[i][j] == '#' && black[i][j] == false){
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}