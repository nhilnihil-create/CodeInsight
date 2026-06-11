#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

int gcd(int a,int b){
	if (a%b == 0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}

}
int lcm(int a,int b){
	return a /gcd(a,b) * b;
}










int main() {

	ll n;
  cin >> n;
  ll d[n+1];
  map <ll,ll> ans;
  rep (i,n) {
    cin >> d[i];
    ans[d[i]]++;
  }
  ll m;
  cin >> m;
  ll t[m+1];
  rep (i,m){
    cin >> t[i];
  }
  bool ok = true;
  rep (i,m){
    if (ans[t[i]]==0){
      ok = false;
    }
    ans[t[i]]--;
  }

  if (ok) cout << "YES" << endl;
  else cout << "NO" << endl;



}

