#include <bits/stdc++.h>
 
using namespace std;

#define esp 1e-9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int l,r;
	cin>>l>>r;
	long long int c=0;
	while(l<=r){
		c++;
		l*=2;
	}
	cout<<c;
	return 0;
}