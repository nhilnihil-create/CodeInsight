#include <bits/stdc++.h>
using namespace std;
 
long long gcd(long x,long y){
    if(y==0)return x;

    return gcd(y,x%y);
}
long long lcm(long x,long y){
    return x*y/gcd(x,y);
}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main()
{
    int a,b;
    cin>>a>>b;

    if(a+b==15){
        cout<<"+"<<endl;
    }else if(a*b==15){
        cout<<"*"<<endl;
    }else{
        cout<<"x"<<endl;
    }

    return 0;
}