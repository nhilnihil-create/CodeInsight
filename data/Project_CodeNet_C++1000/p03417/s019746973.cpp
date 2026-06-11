#include<bits/stdc++.h>
using namespace std;
int main(){
	long long m,n;
	cin>>m>>n;
	if(n==1 || m==1)
	if(n*m>=2)
	cout<<n*m-2;
	else
	cout<<'1';
	else
	cout<<(n-2)*(m-2);
}