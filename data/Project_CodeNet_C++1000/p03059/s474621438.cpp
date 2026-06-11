#include <bits/stdc++.h>
using namespace std;
int main(){
	double a,b,t;
	cin>>a>>b>>t;
	int i=1;
	int sum = 0;
	t+=0.5;
	int c=a;
	//cout<<t<<' ';
	while(c<=t){
	    sum+=b;
	    i++;
	    c=a*i;
	    //cout<<a<<' '; 		
	}
	cout<<sum<<endl;
}