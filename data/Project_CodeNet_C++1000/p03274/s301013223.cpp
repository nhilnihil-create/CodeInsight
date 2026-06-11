#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;

int n,k;
int s0,b0;
int arr[maxn], w[maxn];

int main() {
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&arr[i]);
		w[i] = abs(arr[i]);
	}
	int cs = INF;
	for (int i = 1; i+k-1 <= n; i++) {
		int x,y;
		x = min(abs(arr[i+k-1]),abs(arr[i]));
		y = arr[i+k-1] - arr[i];
		cs = min(cs,x+y);
	}
	printf ("%d\n",cs);
	return 0;
}