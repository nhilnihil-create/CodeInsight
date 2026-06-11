#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int a,b;
	cin>>a>>b;
	if((a*b)&1){
		cout<<"Odd";
	}
	else{
		cout<<"Even";
	}
	return 0;
}