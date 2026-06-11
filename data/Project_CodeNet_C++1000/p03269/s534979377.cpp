#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> opset;
#define SZ(X) ((int)X.size())
#define ALL(I) I.begin(), I.end()
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define eps 1e-12
#define MXN 200005

int L, cnt, n;

int main(){
	cin >> L;
	while((1 << n) <= L) n ++;
	printf("%d %d\n", n, __builtin_popcount(L) + 2 * (n - 1) - 1);
	for(int i = 1; i <= n - 1; i ++){
		printf("%d %d %d\n", i, i + 1, (1 << (i - 1)));
		printf("%d %d 0\n", i, i + 1);
	}
	int tp = 0;
	for(int i = n - 1; i >= 0; i --){
		if(L & (1 << i)){
			if(i < n - 1){
				printf("%d %d %d\n", i + 1, n, tp);
			}
			tp |= (1 << i);
		}
	}
	//printf("%d\n", cnt);
	//assert(cnt == __builtin_popcount(L) + 38 - (L & (1 << 19) ? 1 : 0));
	
}

