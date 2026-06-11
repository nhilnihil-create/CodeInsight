#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s=0,a;
	cin>>n;
	while(n!=0){
		a=n%10;
		n/=10;
		if(a==2) s++;
	}
	cout<<s<<endl;
	return 0;
}