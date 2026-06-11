#include<bits/stdc++.h> 

using namespace std;

int main(){ 
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long k,a,b;
	cin>>k>>a>>b;
	if(b-a<=1){ 
		cout<<k+1;
		return 0;
	} 
	if(k+1<a+2){ 
		cout<<k+1;
		return 0;
	} 
	k++;
	k-=(a+2);
	cout<<b+(k/2)*(b-a)+k%2;

	return 0;
}

