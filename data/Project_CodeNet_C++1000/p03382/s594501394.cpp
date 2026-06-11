#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i=0; i<n; i++) scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int hf = (arr[n-1]+1)/2;
	int ans = -1;
	int md = INT_MAX;
	for (int i=0; i<n-1; i++) {
		if (abs(hf-arr[i])<md) {
			md=abs(hf-arr[i]);
			ans=arr[i];
		}
	}
	printf("%d %d\n", arr[n-1], ans);
}
