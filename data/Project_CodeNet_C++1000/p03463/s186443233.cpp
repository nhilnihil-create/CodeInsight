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

    int N,A,B;
    cin>>N>>A>>B;

    if((B-1-A)%2==1){
        cout<<"Alice"<<endl;
    }else{
        cout<<"Borys"<<endl;
    }

    return 0;
}