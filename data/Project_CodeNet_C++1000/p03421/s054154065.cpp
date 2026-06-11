#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,t=0;cin>>n>>a>>b;
	if(a+b-1>n||(long long)a*b<n)cout<<-1;
	else{
		for(int i=0;i<a;i++)
		{
			int rem=min((n-t)-(a-i-1),b);
			for (int j=0;j<rem;j++)cout<<t+rem-j<<" ";
			t+=rem;
		}
	}
	return 0;
}