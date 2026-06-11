#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mem(x, a) memset(x, a, sizeof(x))
#define AC ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;

const int maxn = 2e5 + 50;
int n;
int bit[maxn], a[maxn], h[maxn];

int lowbit(int x){
	return x & -x;
}

void modify(int x, int val){
	for(int i = x; i <= n; i += lowbit(i)){
		bit[i] = max(val, bit[i]);
	}
}

int query(int x){
	int ans = -INF;
	for(int i = x; i >= 1; i -= lowbit(i)){
		ans = max(ans, bit[i]);
	}
	return ans;
}

main(){
	AC;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> h[i];
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++){
		int val = query(h[i]) + a[i];
		modify(h[i], val);
	}
	cout << query(n) << "\n";
}