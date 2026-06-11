// 20:23 - 20:32
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define lch (o << 1)
#define rch (o << 1 | 1)

typedef double db;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> pint;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;

ll s[N];

// (st, ed]
int BSearch(int L, int R, int st, int ed){
	while(L < R){
		int M = (L+R) / 2;
		ll s1 = s[M] - s[st];
		ll s2 = s[ed] - s[M];
		if(s1 < s2) L = M + 1;
		else R = M;
	}
	return L;
}

ll Cal(int x, int y, int z, int n){
	vector<ll> t;
	t.push_back(s[x]);
	t.push_back(s[y] - s[x]);
	t.push_back(s[z] - s[y]);
	t.push_back(s[n] - s[z]);
	sort(t.begin(), t.end());
	return t.back() - t.front();
}

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	for(int i=1; i<=n; i++){
		cin >> s[i];
		s[i] += s[i-1];
	}

	ll ans = INF_LL;
	for(int i=2; i<=n-2; i++){
		int p1 = BSearch(1, i, 0, i);
		int p2 = BSearch(i+1, n, i, n);
		for(int j=-1; j<=0; j++)
			for(int k=-1; k<=0; k++)
				ans = min(ans, Cal(p1 + j, i, p2 + k, n));
	}
	cout << ans << endl;

	return 0;
}