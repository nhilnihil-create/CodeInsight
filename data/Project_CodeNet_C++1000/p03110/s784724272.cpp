#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	int n;
  	cin>>n;
  	long double x=0,t;string s;
  	for(int i=0;i<n;i++){
    	cin>>t>>s;
    	if(s[0]=='J') x+=t;
      	else x+=380000.0*t;
    }
  	cout<<fixed<<setprecision(12)<<x;
}