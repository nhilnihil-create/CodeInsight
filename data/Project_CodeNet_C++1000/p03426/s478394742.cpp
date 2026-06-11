#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 310;
typedef pair<int,int> pi;
#define f first 
#define s second

int h,w,d;
int A[maxn][maxn];
int cost[maxn][maxn];
map <int, pi> mp;

void dfs(int i, int j) {
	int cur = A[i][j];
	if (mp.find(cur + d) == mp.end()) return;
	pi nn = mp[cur + d];
	cost[nn.f][nn.s] = cost[i][j] + abs(nn.f - i) + abs(nn.s - j);
	dfs(nn.f, nn.s);
}

int main() {
	cin >> h >> w >> d;
	for (int i =1;i<=h;i++) {
		for (int j=1;j<=w;j++) {
			cin >> A[i][j];
			mp[A[i][j]] = pi(i,j);
		}
	}
	memset(cost,-1,sizeof cost);
	for (int i =1;i<=h;i++) {
		for (int j=1;j<=w;j++) {
			if (cost[i][j] == -1) {
				cost[i][j] = 0;
				dfs(i,j);
			}
		}
	}
	
	int q;
	cin >>q;
	for (int i =0;i<q;i++) {
		int l,r; cin >> l >> r;
		pi n1 = mp[l];
		pi n2 = mp[r];
		cout << cost[n2.f][n2.s] - cost[n1.f][n1.s] << "\n";
		
	}
}


