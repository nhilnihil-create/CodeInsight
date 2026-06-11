#include<iostream>
using namespace std;

int main(){
	int k;
	cin>>k;
	if(k%2==0)	cout<<k*k/4;
	else		cout<<(k-1)/2*((k-1)/2+1);
} 