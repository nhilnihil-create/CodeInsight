#include<bits/stdc++.h>
using namespace std;
string a;
int ans=1000000000;
int main(){
	cin>>a;
	for(int i=1;i<a.length();i++){
		if(a[i]!=a[i-1]){
			ans=min(ans,max(i,int(a.length())-i));
		}
	}
	printf("%d",min(ans,int(a.length())));
	return 0;
}