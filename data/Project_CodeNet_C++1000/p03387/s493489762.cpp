#include<bits/stdc++.h>
using namespace std;
int a[3];
int main(){
	int ans=0;
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if((a[0]+a[1])%2==0){
		ans=(a[1]-a[0])/2+(a[2]-a[1]);
	}
	else{
		a[1]++;
		a[2]++;
		ans=1+((a[1]-a[0])/2+(a[2]-a[1]));
	}
	cout<<ans;
}