#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int a,b; cin>>a>>b;
	if(a+b==15) cout <<"+";
	else if(a*b==15) cout<<"*";
	else cout<<"x";
	cout<<"\n";
	return 0;
}