#include<iostream>
using namespace std;
int solve(int x) {
	int y=0;
	while(x%100==0) {
		x/=100;
		y++;
	}
return y;
}
int main() {
	int d,n;
	cin>>d>>n;
	int i=0,ct=0;
	while(i<n) {
		ct++;
	   if(solve(ct)==d) 
		   i++;
	}
   cout<<ct<<'\n';
	
}