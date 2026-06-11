#include<bits/stdc++.h>
#define el endl
#define F(k) for(int i=0;i<k;i++) 
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	if(a+b==15){
		cout<<"+"<<el;
		return 0;
	}
	if(a*b==15){
		cout<<"*"<<el;
		return 0;
	}
	cout<<"x"<<el;
	return 0;
}