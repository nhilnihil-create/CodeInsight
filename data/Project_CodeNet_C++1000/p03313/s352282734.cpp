#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 1 << 20;
lli n;
lli a[e5];
lli ans[e5];
lli ai[e5];
lli aj[e5];
lli k;

int main(){
	cin >> n;
	k = pow(2,n);
	for(lli i = 0;i < k;i++) cin >> a[i];
	iota(ai,ai+k,0ll);
	for(lli i = 0;i <= n;i++){
		for(lli b = 1;b < (1<<n);b++){
			if((b&(1<<i)) == 0) continue;
			lli  v[] = {ai[b],aj[b],ai[b^(1<<i)],aj[b^(1<<i)]};
			lli mem = 0;
			lli idx1 = 0,idx2 = 0;
			for(lli i = 0;i < 4;i++){
				if(a[v[i]] > mem){
					idx1 = v[i];
					mem = a[v[i]];
				}
			}
			mem = 0;
			for(lli i = 0;i < 4;i++){
				if(v[i] == idx1) continue;
				if(a[v[i]] > mem){
					idx2 = v[i];
					mem = a[v[i]];
				}
			}

			ai[b] = idx1;
			aj[b] = idx2;

		}
	}
	for(lli i = 0;i < k;i++){
		ans[i] = a[ai[i]]+a[aj[i]];
	}
	// for(lli i = 0;i < k;i++){
	// 	for(lli j = i+1;j < k;j++){
	// 		ans[i|j] = max(ans[i|j], a[i]+a[j]);
	// 	}
	// }
	lli max_ans = 0;
	for(lli i = 1;i < k;i++){
		max_ans = max(max_ans, ans[i]);
		cout << max_ans << endl;
	}


}
