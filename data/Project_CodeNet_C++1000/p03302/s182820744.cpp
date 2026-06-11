#include <bits/stdc++.h>
using namespace std;

int main() {
    double n,m,a,b,c,sum=0,flag=0;
	string s;
	cin>>a>>b;
	if(a+b==15){
	    cout<<'+'<<'\n';
	}
	else if(a*b==15){
	    cout<<'*'<<'\n';
	}
	else{
	    cout<<'x'<<'\n';
	}
    return 0;
}
