#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int (i)=int (a);i<=int (b);i++)
#define int long long
int a,b;
int finxor(int n){
	int m=n%4;
	if(m==0){
		return n;
	}
	else if(m==1){
		return 1;
	}
	else if(m==2){
		return n+1;
	}
	else return 0;
}
int findxor(int a,int b){
	return finxor(a-1)^finxor(b);
}
signed main(){
	cin>>a>>b;
	if(a==b){
		cout<<a;
		return 0;
	}
	a=max(a,(int)1);
	cout<<findxor(a,b);
}
