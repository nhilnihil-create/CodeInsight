#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	int n;
	cin >> n;
	vector<int> c(n-1),s(n-1),f(n-1);
	rep(i,n-1){
		cin >> c[i] >> s[i] >> f[i];
	}
	vector<int> ans(n,0);
	rep(i,n-1){
		int now = 0;
		for(int j = i; j < n-1; j++){
			if(now <= s[j]){
				now = s[j];
				now += c[j];
			}else{
				now = s[j] + f[j]*(int)((f[j]+now-s[j]-1.0)/f[j]);
				now += c[j];
			}
		}
		ans[i] = now;
	}
	rep(i,n) cout << ans[i] << endl;
	return 0;
}