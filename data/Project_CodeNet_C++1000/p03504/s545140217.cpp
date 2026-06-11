#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 100005;
const int M = 200005;

int f[M], s[N], t[N], c[N], tot[M];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, C;
	cin>>n>>C;
	for(int i = 1; i <= n; i++){
		cin>>s[i]>>t[i]>>c[i];
	}
	memset(tot, 0, sizeof(tot));
	for(int i = 1; i <= C; i++){
		memset(f, 0, sizeof(f));
		for(int j = 1; j <= n; j++){
			if(c[j] == i){
				f[2*s[j] - 1]++;
				f[2*t[j] + 1]--;
			}
		}
		for(int j = 1; j < M; j++){
			f[j] += f[j - 1];
		}
		for(int j = 1; j < M; j++){
			if(f[j])tot[j]++;
		}
	}
	int ans = 0;
	for(int i = 1; i < M; i++){
		ans = max(ans, tot[i]);
	}
	cout<<ans<<'\n';

	return 0;
}