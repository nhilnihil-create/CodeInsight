#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	cin>>a>>b>>c;
	int m=max(a,max(b,c));
	if((m*3-(a+b+c))%2==0)cout<<(m*3-(a+b+c))/2;
	else cout<<(m*3-(a+b+c))/2+2;
}