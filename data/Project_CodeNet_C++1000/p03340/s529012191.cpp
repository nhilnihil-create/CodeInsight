#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;
const int maxn = 2e5 + 10;
#define ll long long
ll a[200005];
ll b[200005], c[200005], d[200005], ans; 
int upperbound(int l, int r, ll s){
        while(l<r){
            int m = (l+r)/2;
            ll h = b[m] ^ b[s - 1];
            if(c[m] - c[s - 1] - h <= 0) 
 				l = m + 1;
            else    
				r = m;
        }
        return l;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i] ^ b[i - 1];
		c[i] = a[i] + c[i - 1]; 
		d[i] = c[i] - b[i];
	}
	c[n + 1] = 1e17;
	for (int i = 1; i <= n; i++)
	{
		int x = upperbound(i, n + 1, i);
		ans += x - i;		
	}
	printf("%lld", ans);
}
