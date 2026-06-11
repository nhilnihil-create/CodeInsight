#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
	int n,x=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		x=max(x,a[i]);
	}
	int t=0,l=0;
	for(int i=0;i<n;i++){
		if(t<min(a[i],x-a[i])){
			t=min(a[i],x-a[i]);
			l=a[i];
		}	
	}
	cout<<x<<' '<<l;
	return 0;
}