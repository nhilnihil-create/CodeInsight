//header{{{
#include<bits/stdc++.h>
  
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define setout(n,x) setw(n) << setfill(x)
#define Fixed fixed << setprecision(10)
#define int long long
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod = 1e9+7; 

template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
  
int gcd(int a,int b){ return b ? gcd(b,a % b) : a;}
int lcm(int a,int b){ return a / gcd(a,b) * b;}
//}}}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n){
		cin >> a[i];
	}
	int cnt = 0;
	rep(i,n-1){
		if(a[i] == a[i+1]){
			++cnt;
			++i;
		}
	}
	cout << cnt << '\n';
	return 0;
}
