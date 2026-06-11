#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,z=0;
	cin>>n;
	if(n/1000==2)z++;
	if(n%1000/100==2)z++;
	if(n%100/10==2)z++;
	if(n%10==2)z++;
	cout<<z;
}