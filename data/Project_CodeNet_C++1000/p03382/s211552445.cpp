#include <bits/stdc++.h>
using namespace std;

int n;
int a[100004];
int main() {
	cin>>n;
	for(int i = 0; i < n; i++)	cin>>a[i];
	sort(a,a+n);
	int b = a[n-1];
	int l = b/2;
	int idx = lower_bound(a,a+n-1,l)-a;
	if(idx == n-1){
		cout<<a[n-1]<<" "<<a[n-2];
		return 0;
	}
	if(idx == 0){
		cout<<a[n-1]<<" "<<a[0];
		return 0;
	}
	int c = a[idx];
	if(c>l)	c = b-c;
	if(a[idx-1]<c)	cout<<a[n-1]<<" "<<a[idx];
	else	cout<<a[n-1]<<" "<<a[idx-1];
	return 0;
}