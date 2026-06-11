#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int a[100010];
	int m = 0;
	long long minx = 10000000000;
	int ans;
	int n, i;
	scanf("%d", &n);
	for (i = 0;i<n;i++){
		scanf("%d", &a[i]);
		m = max(m, a[i]);
	}
	sort(a, a + n);
	for (i = 0;i<n - 1;i++){
		if (abs(a[n - 1] / 2 - a[i]) <= minx){
			minx = abs(a[n - 1] / 2 - a[i]);
			ans = a[i];
		}
	}
	printf("%d %d", m, ans);
}
