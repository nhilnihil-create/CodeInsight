#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,ans,ans1,ans2,ans3,ans4;
	cin>>a>>b;
	ans1=a+b;
	ans2=a-b;
	ans3=a*b;
	ans4=max(ans1,ans2);
	ans=max(ans4,ans3);
	cout<<ans<<endl;
	return 0;
	
	
}