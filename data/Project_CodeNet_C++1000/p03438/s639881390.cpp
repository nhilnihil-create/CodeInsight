#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1e9+7;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
typedef pair<ll, ll> pll;;


int main() {
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i]; 
  for (int i = 0; i < n; i++) cin >> b[i]; 

  long long cnt_a = 0, cnt_b = 0;

  for (int i=0; i<n; i++){
    if(a[i] > b[i]) cnt_a += (a[i] - b[i]);
    if(b[i] > a[i]) cnt_b += (b[i] - a[i]) / 2;
  }

  if(cnt_b >= cnt_a) cout << "Yes" << endl;
  else cout << "No" << endl;
}
