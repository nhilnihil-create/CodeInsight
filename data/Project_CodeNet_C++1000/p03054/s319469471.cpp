#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int INF = 987654321;
const ll MOD = 1000000007;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int h, w, n;
int r, c;
string s, t;
vi S;
vi T;

bool inRange(int y, int x) {
  return y >= 0 && y < h && x >= 0 && x < w;
}

bool f(int d, int rd) {
  int y = r;
  int x = c;

  for(int i=0; i<n; ++i) {
    if(S[i] == d) {
      y += dy[d];
      x += dx[d];
    }

    if(!inRange(y, x)) {
      return true;
    }

    if(T[i] == rd) {
      y += dy[rd];
      x += dx[rd];
    }
    if(!inRange(y,x)) {
      y -= dy[rd];
      x -= dx[rd];
    }
  }

  return false;
}

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  //freopen("in.txt", "r", stdin);
  cin >> h >> w >> n;
  cin >> r >> c;
  r--; c--;
  cin >> s;
  cin >> t;
  S.resize(n);
  T.resize(n);
  rep(i,0,n) {
    if(s[i] == 'U') {
      S[i] = 0;
    } else if(s[i] == 'R') {
      S[i] = 1;
    } else if(s[i] == 'D') {
      S[i] = 2;
    } else if(s[i] == 'L') {
      S[i] = 3;
    }

    if(t[i] == 'U') {
      T[i] = 0;
    } else if(t[i] == 'R') {
      T[i] = 1;
    } else if(t[i] == 'D') {
      T[i] = 2;
    } else if(t[i] == 'L') {
      T[i] = 3;
    }
  }

  bool outOfBoard = false;
  outOfBoard = f(0,2) || f(1,3) || f(2,0) || f(3,1);
  if(outOfBoard) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}