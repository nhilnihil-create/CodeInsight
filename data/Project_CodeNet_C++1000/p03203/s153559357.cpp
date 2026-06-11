#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9;
const ll INF = 1e18;
int n, h, w, ans;
vector< int > v[N];
int main(){
	scanf("%d%d%d", &h ,&w, &n);
	for(int i = 0; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		v[y].pb(x);
	}
	ans = h + 1;
	for(int y = 1, x = 1; y <= w; y++){
		sort(v[y].begin(), v[y].end());
		for(auto j : v[y])
			if(j > x)
				ans = min(ans, j);
			else if(j == x)
				x++;
		x++;
	}
	printf("%d", ans - 1);
	return 0;
}
