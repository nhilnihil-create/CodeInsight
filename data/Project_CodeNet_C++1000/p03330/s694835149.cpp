#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int M = 35;
int d[M][M], cnt[3][M];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, C;
	cin>>n>>C;
	for(int i = 1; i <= C; i++){
		for(int j = 1; j <= C; j++){
			cin>>d[i][j];
		}
	}
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x; cin>>x;
			cnt[(i+j)%3][x]++;
		}
	}
	int col[3];
	ll ans = LLONG_MAX;
	for(col[0] = 1; col[0] <= C; col[0]++){
		for(col[1] = 1; col[1] <= C; col[1]++){
			for(col[2] = 1; col[2] <= C; col[2]++){
				if(col[0] == col[1] || col[1] == col[2] || col[2] == col[0])continue;
				ll cost = 0;
				for(int i = 0; i < 3; i++){
					for(int j = 1; j <= C; j++){
						cost += cnt[i][j]*1LL*d[j][col[i]];
					}
				}
				ans = min(ans, cost);
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}