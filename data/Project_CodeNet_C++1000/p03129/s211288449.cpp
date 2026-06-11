#include <cstdio>
#include <vector>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int n, k;

int main(){
	scanf("%d%d", &n, &k);
    printf("%s", 2 * k <= n + 1 ? "YES" : "NO");
    return 0;
}
