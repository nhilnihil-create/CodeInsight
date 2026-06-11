#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, h, w, i, br=0;
	scanf("%d%d%d", &n, &h, &w);
	int a[n], b[n];

	for(i=0; i<n; i++){
		scanf("%d%d", &a[i], &b[i]);
		if(a[i]>=h && b[i]>=w) br++;
	}

	printf("%d", br);

    return 0;
}
