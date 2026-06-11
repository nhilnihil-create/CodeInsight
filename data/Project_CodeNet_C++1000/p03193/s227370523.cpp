#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,h,w,a,b,ans=0;
	cin>>n>>h>>w;
	while(cin>>a>>b){
		if(h<=a&&w<=b)
			ans++;
	}
	cout<<ans<<endl;
}
