#include <bits/stdc++.h>
using namespace std;
 
int gcd(int x,int y){
    if(y==0)return x;

    return gcd(y,x%y);
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){

    int A,B,C,ans=0,f=0;

    cin>>A>>B>>C;

    ans = min(A+B+1,C) + B;

    cout<<ans<<endl;

    return 0;
}