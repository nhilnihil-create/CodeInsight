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
	vi b(n); rep(i,n) cin >> b[i];
	vi num(n); rep(i,n) num[i] = i+1;
	vector<bool> in(n,true);
	vi ans(n);
	rep(i,n){
		bool ext = true;
		for(int j=n-1; j>=0; j--){
			if(in[j]&&(b[j]==num[j])){
				in[j] = false;
				for(int k=j+1; k<n; k++) num[k]--;
				ans[i] = num[j];
				ext = false;
				break;
			}
		}
		if(ext){
			cout << -1 << endl;
			return 0;
		}
	}
	REV(ans);
	rep(i,n) cout << ans[i] << endl;
}
