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
    int ans=0;
    string N;
    cin>>N;

    if(N[0]=='2')ans++;
    if(N[1]=='2')ans++;
    if(N[2]=='2')ans++;
    if(N[3]=='2')ans++;

    cout<<ans<<endl;

    return 0;
}