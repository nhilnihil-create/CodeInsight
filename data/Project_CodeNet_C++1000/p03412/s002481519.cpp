#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#ifdef LOCAL
#define cerr cout
#else
#endif

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N = 200005;
int a[N], b[N];
const int M = 29;
vector<int> va[M][2], vb[M][2];
int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		for(int j = 0; j < M; j++){
			va[j][a[i] >> j & 1].push_back(a[i] % (1 << j));
		}
	}

	for(int i = 1; i <= n; i++){
		sd(b[i]);
		for(int j = 0; j < M; j++){
			vb[j][b[i] >> j & 1].push_back(b[i] % (1 << j));
		}
	}

	for(int i = 0; i < M; i++)
		for(int j = 0; j < 2; j++)
			sort(vb[i][j].begin(), vb[i][j].end());
	ll ans = 0;
	for(int i = 0; i < M; i++){
		int ans1 = 0;
		for(int j = 0; j < 2; j++)
			for(int k = 0; k < 2; k++){
				int now = j ^ k;
				for(int t : va[i][j]){
					int num = upper_bound(vb[i][k].begin(), vb[i][k].end(), (1 << i) - 1 - t) - vb[i][k].begin();
					ans1 ^= ((num & 1) * now) & 1;
					ans1 ^= (((((int)vb[i][k].size()) - num) & 1) * (now ^ 1)) & 1;
				}
			}
			ans += ans1 << i;
	}
	printf("%lld\n", ans);
}