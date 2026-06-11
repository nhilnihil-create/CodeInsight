#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	int n; scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	swap(*max_element(a+1, a+n+1), a[1]);
	int df=0, dfi=0;
	for(int i=2; i<=n; ++i){
		int tmp = min(a[1]-a[i], a[i]);
		if(tmp >= df){
			df = tmp; dfi = i;
		}
	}
	printf("%d %d\n", a[1], a[dfi]);
	return 0;
}
