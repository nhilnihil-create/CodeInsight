#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

int main(void) {
	int n; cin >> n;
	string s; cin >> s;
	vi ws(n,0), bs(n,0);
	if(s[0]=='.') ws[0]++; else bs[0]++;
	rep(i,n-1){
		ws[i+1] = ws[i];
		bs[i+1] = bs[i];
		if(s[i+1]=='.') ws[i+1]++; else bs[i+1]++;
	}
	int ans = INF;
	ans = min(ans,ws[n-1]);
	ans = min(ans,bs[n-1]);
	rep(i,n){
		int w = bs[i];
		int b = ws[n-1]-ws[i];
		ans = min(ans,w+b);
	}
	cout << ans << endl;
}
