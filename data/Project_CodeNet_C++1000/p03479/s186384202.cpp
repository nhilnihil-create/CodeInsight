#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b;
	cin>>a>>b;
	long long s=0;
	while(a<=b){
		s++;
		a*=2;
	}
	cout<<s;
}