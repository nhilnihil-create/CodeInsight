#include <bits/stdc++.h>

using namespace std;

int main(){
	// int n;
	// cin>>n;
	int a[5];
	for(int i=0;i<5;i++){
		cin>>a[i];
	}
	sort(a,a+5);
	int k;
	cin>>k;
	cout<<((a[4]-a[0]<=k)?"Yay!":":(");
}