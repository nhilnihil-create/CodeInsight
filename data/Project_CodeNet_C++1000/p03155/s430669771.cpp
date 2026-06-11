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
    int N,H,W;
    cin>>N>>H>>W;

    cout<<(N-H+1)*(N-W+1)<<endl;

    return 0;
}