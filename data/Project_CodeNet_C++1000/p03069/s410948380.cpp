#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int n;
  cin >> n;
  string s;
  cin >> s;

  int black = 0, white = 0;
  for(int i = 0; i < n; ++i){
    if(s[i] == '#') black++;
    else white++;
  }

  int ans = black;
  black = 0;
  for(int i = 0; i < n; ++i){
    ans = min(ans, white + black);
    if(s[i] == '#') black++;
    else white--;    
  }

  cout << ans << endl;

	return 0;
}

