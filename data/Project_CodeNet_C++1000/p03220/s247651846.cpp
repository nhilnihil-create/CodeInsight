#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	int n,t,a,h,ans;
	double ans1=100000;
	cin>>n>>t>>a;
	for(int i=0;i<n;i++){
		cin>>h;
		if(ans1>abs(a-(t-h*0.006))){
			ans=i+1;
			ans1=abs(a-(t-h*0.006));
		}
	}
	cout<<ans<<endl;
	return(0);
}