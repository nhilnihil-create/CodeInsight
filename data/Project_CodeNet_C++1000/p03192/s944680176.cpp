#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a=0;
	cin>>n;
		int b;
	while(n>0)
	{
		b=n%10;
		if(b==2)
			a++;
		n=n/10;
	}
	cout<<a<<endl;
	return 0;
}
