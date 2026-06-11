#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a, b;

int main() {
	cin>>n>>a>>b;
	if((a - b)&1) cout<<"Borys"<<endl;
	else cout<<"Alice"<<endl;
	return 0;
}