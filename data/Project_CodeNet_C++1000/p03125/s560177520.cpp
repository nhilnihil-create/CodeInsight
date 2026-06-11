#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int a,b;
	cin>>a>>b;
	if(b%a==0){
		cout<<a+b;
	}
	else{
		cout<<b-a;
	}
	return 0;
}