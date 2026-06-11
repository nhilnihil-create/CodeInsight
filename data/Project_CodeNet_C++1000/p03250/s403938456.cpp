#include<bits/stdc++.h>
using namespace std;

int a,b,c,n;

int main(){
	cin>>a>>b>>c;
	n = max(max(a,b),c);
	cout<<n * 10 + (a + b + c - n)<<endl;
}
