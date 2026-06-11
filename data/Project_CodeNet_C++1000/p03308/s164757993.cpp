#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	int mn=a[0],mx=a[0];
	for(int i=1;i<n;i++){
		if(mn>a[i])
			mn=a[i];
		if(mx<a[i])
			mx=a[i];
	}
	
	cout<<mx-mn<<endl;
}