#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0;
	string a,b,c;
	cin>>n>>a>>b>>c;
	for(int i=0;i<n;i++)
		ans+=(a[i]==b[i]&&b[i]==c[i])+(a[i]==b[i]||b[i]==c[i]||c[i]==a[i]);
	cout<<2*n-ans<<endl;
}
