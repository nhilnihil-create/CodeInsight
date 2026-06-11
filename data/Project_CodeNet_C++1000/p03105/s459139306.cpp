#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int a,b,c;
	cin>>a>>b>>c;
	if(b/a<=c){
		cout<<b/a;
	}
	else{
		cout<<c;
	}
	return 0;
}