#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
	ll lu[87];
	lu[0]=2,lu[1]=1;
	for(int i=2;i<87;i++){
		lu[i]=lu[i-1]+lu[i-2];
	}
	int n;
	cin>>n;
	cout<<lu[n];
	return 0;
}