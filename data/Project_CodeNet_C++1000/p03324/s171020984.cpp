#include<bits/stdc++.h>
using namespace std;
#define int 	long long int

int32_t main(){
	
	int d,k;
	cin>>d>>k;

	int val=(int)pow(100,d);
	if(k!=100)
		cout<<val*k<<endl;
	else
		cout<<val*(k+1)<<endl;

	return 0;
}


