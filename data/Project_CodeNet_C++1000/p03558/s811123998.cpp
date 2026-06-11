#include <cstdio>
#include<iostream>
 
using namespace std; 
 
int used[100001];
 
void dfs(int a, int b, const int k, int &ans) {
	if(used[a] <= b) return;
	else used[a] = b;
	if(a == 0) {
		ans = min(ans,b);
		return;
	}
	if (b + 1 < ans) dfs((a + 1) % k, b + 1, k, ans);
	dfs((a * 10) % k, b, k, ans); 
} 
 
int main() {
        int k, ans = 0;
        scanf("%d", &k);
        int kk = k;
        while (kk > 0) { 
                ans += kk % 10;
                kk /= 10;
        }
        for (int i = 0; i <= k; i ++) used[i] = 1 << 30;
	dfs(1, 1, k, ans);
        printf("%d\n", ans);
	return 0;
}
