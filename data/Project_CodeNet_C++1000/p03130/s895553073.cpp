#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	map<int,int> deg;
	int mx=0;
	for (int i=0; i<3; i++) {
		int a,b; cin>>a>>b; deg[a]++; deg[b]++;
		mx=max({mx,deg[a],deg[b]});
	}
	cout<<(mx<=2?"YES":"NO")<<"\n";
	return 0;
}