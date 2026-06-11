#include<bits/stdc++.h>
using namespace std;
int a[4],b[4];
int k[5],c[5];

int main(){
	for(int i=1;i<=3;i++) cin>>a[i]>>b[i],k[a[i]]++,k[b[i]]++;
	for(int i=1;i<=4;i++) c[k[i]]++;
	if(c[1]==2&&c[2]==2) cout<<"YES\n";
	else cout<<"NO\n";
	
	return 0;
}