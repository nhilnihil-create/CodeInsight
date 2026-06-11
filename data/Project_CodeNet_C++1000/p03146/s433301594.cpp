#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
	int a[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,t=1;
	cin>>n;
	while(n!=4&&n!=1&&n!=2)
	{

		if(n%2==0)n/=2;
		else n=3*n+1;
		t++;
	}

		cout<<t+3;

}
