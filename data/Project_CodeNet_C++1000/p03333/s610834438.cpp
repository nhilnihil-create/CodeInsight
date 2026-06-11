#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int l[100005], r[100005];
int p1[100005], p2[100005];
bool vis[100005];

bool cmp1(const int a, const int b){
	return l[a] > l[b];
}
bool cmp2(const int a, const int b){
	return r[a] < r[b];
}

int main(){
	int n;
	scanf("%d", &n);
	LL ans = 0, ans1 = 0, ans2 = 0;
	for(int i=1;i<=n;i++){
		scanf("%d%d", &l[i], &r[i]);
		p1[i] = i, p2[i] = i;
	}

	sort(p1+1, p1+1+n, cmp1);
	sort(p2+1, p2+1+n, cmp2);

	int cur1 = 0, cur2 = 0;
	int c1 = 1, c2 = 1;
	for(int i=1;i<=n;i++){
		if(i%2 == 1){
			while(vis[p1[c1]]) c1++;
			vis[p1[c1]] = 1;
			if(cur1 >= l[p1[c1]] && cur1 <= r[p1[c1]]) continue;
			ans1 += abs(cur1-l[p1[c1]]);
			cur1 = l[p1[c1]];
		}
		else{
			while(vis[p2[c2]]) c2++;
			vis[p2[c2]] = 1;
			if(cur1 >= l[p2[c2]] && cur1 <= r[p2[c2]]) continue;
			ans1 += abs(cur1-r[p2[c2]]);
			cur1 = r[p2[c2]];
		}
	}
	ans1 += abs(cur1);
	c1 = 1, c2 = 1;
	memset(vis, 0, sizeof(vis));
	for(int i=1;i<=n;i++){
		if(i%2 == 1){
			while(vis[p2[c2]]) c2++;
			vis[p2[c2]] = 1;
			if(cur2 >= l[p2[c2]] && cur2 <= r[p2[c2]]) continue;
			ans2 += abs(cur2-r[p2[c2]]);
			cur2 = r[p2[c2]];
		}
		else{
			while(vis[p1[c1]]) c1++;
			vis[p1[c1]] = 1;
			if(cur2 >= l[p1[c1]] && cur2 <= r[p1[c1]]) continue;
			ans2 += abs(cur2-l[p1[c1]]);
			cur2 = l[p1[c1]];
		}
	}
	ans2 += abs(cur2);
	ans = max(ans1, ans2);
	printf("%lld\n", ans);
}