#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 220005;

int n, a[MAXN], b[MAXN];

struct bit{
	int tree[MAXN];
	void add(int x, int v){
		while(x < MAXN){
			tree[x] += v; 
			x += x & -x;
		}
	}
	void clear(){
		memset(tree, 0, sizeof(tree));
	}
	int query(int x){
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit;

lint trial(int x){
	bit.clear();
	b[0] = n + 2;
	for(int i=1; i<=n; i++){
		if(a[i] <= x) b[i] = 1;
		else b[i] = -1;
		b[i] += b[i-1];
	}
	lint ret = 0;
	for(int i=1; i<=n; i++){
		bit.add(b[i-1], 1);
		ret += bit.query(b[i] - 1);
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	lint pcnt = 1ll * n * (n + 1) / 2;
	pcnt = (pcnt + 2) / 2;
	int s = 0, e = 1e9;
	while(s != e){
		int m = (s+e)/2;
		if(trial(m) < pcnt) s = m + 1;
		else e = m;
	}
	cout << s << endl;
}
