#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0), ios::sync_with_stdio(false);
	int n,k; cin >> n >> k;
	string s; cin >> s;
	vi sum;
	sum.push_back(0);
	rep(i,n){
		int cnt = 0;
		char tmp = s[i];
		while(s[i] == tmp){
			cnt++;
			i++;
		}
		i--;
		sum.push_back(cnt);
	}
	int sz = sum.size();
	rep(i,sz-1) sum[i+1] += sum[i];
	int ans = 0;
	if(s[0] == '1'){
		rep(i,sz){
			if(i%2) chmax(ans,sum[min(sz-1,i+k*2)]-sum[i]);
			else chmax(ans,sum[min(sz-1,i+k*2+1)]-sum[i]);
		}
	}else{
		rep(i,sz){
			if(i%2) chmax(ans,sum[min(sz-1,i+k*2+1)]-sum[i]);
			else chmax(ans,sum[min(sz-1,i+k*2)]-sum[i]);
		}
	}
	cout << ans;
	cout << "\n";
	return 0;
}
