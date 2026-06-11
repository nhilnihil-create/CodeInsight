#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
	cin >> n ;
	int a[n], diff[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	diff[0] = a[0];
	for(int i=1; i<n; i++)
		diff[i] = a[i]-a[i-1];
	int ans = 0;
	for(int i=0; i<n; i++)
		if(diff[i]>0)
			ans += diff[i];
	cout << ans << endl;
}