#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a, b,ans =0;
	
	cin>> a>>b;
	if(a<=5){
		ans = 0;
	}else if(6<=a&&a<=12){
		ans = b/2;
	}else{
		ans = b;
	}
	cout<<ans<<endl;
}