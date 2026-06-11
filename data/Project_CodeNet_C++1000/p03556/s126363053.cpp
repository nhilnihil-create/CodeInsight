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

    int N,ans=1;
    cin>>N;
    while(1){
        if(ans*ans>N)break;
        ans++;
    }

    cout<<(ans-1)*(ans-1)<<endl;
    return 0;
}