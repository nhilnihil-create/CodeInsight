#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  ll n;
  cin >> n;
  vl d(n);
  rep(i,n){
    cin >> d[i];
  }
  d.pb(INF);
  sort(all(d));
  ll m;
  cin >> m;
  vl t(m);
  rep(i, m){
    cin >> t[i];
  }
  bool OK = true;
  rep(i, m){
    ll key = t[i];
    int left = 0, right = sz(d) - 1; // 配列 a の左端と右端
    ll a = -1;
    int mid = left + (right - left) / 2; // 区間の真ん中
    while (right >= left){
      mid = left + (right - left) / 2; 
      if (d[mid] == key){
        a = mid;
        break;
      }
      else if (d[mid] > key){
        right = mid - 1;
      }
      else if(d[mid] < key){
        left = mid + 1;
      }
    }
    if(a==-1){
      OK = false;
      break;
    }
    else{
      d.erase(d.begin() + mid);
    }
    
  }
  if(OK){
    print("YES");
  }
  else{
    print("NO");
  }
}