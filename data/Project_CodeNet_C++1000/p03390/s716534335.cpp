#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main(){
	int n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%lld %lld", &x, &y);
		z = (long long)sqrt(x*y);
		if (z*z == x*y)z--;
		if (x == y)ans = 2 * z;
		else if ((z*(z + 1)) < (x*y)){
			ans = 2 * z - 1;
		}
		else ans = 2 * z - 2;
		printf("%lld\n", ans);
	}




	return 0;
}