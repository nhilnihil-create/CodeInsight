#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

int main(){
	int n;
	cin >> n;
	bool ok = true;
	int a = 0, b = 0, ab = 0;
	rep(i,n) {
		string s;
		cin >> s;
		if(s[0]=='B') b++;
		if(s[s.length()-1]=='A') a++;
		if((s[0]=='B')^(s[s.length()-1]=='A')) ok = false;
		rep(j,s.length()-1){
			if(s.substr(j,2)=="AB") ab++;
		}
	}
	int ans = ab+min(a,b)-(a!=0&&a==b&&ok?1:0);
	cout << ans << endl;
}