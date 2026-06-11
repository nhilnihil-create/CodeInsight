#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;
int c; cin >> c;
  vector<vector<int> > mat(n, vector<int>(m));
	vector<int> b(m);
  forn(i, 0, m)cin >> b[i];
  forn(i, 0, n){
	  forn(j, 0, m){
		  cin >> mat[i][j];
	  }
  }
int ans = 0;
  forn(i, 0, n){
	  ll sum = c;
	  forn(j, 0, m){
		  sum += mat[i][j]*b[j];
	  }
	  if(sum > 0)ans++;
  }
  cout << ans << endl;

}


