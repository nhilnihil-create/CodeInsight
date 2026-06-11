#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,v[20],c,s=0; cin>>n;
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++){
		cin>>c;
		if(v[i]-c>0) s+=v[i]-c;
	}
	cout<<s;
}