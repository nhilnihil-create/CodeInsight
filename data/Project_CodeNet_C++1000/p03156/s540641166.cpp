#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	int a,b; cin>>a>>b;
	map<int,int> ct;
	for (int i=0; i<n; i++) {
		int p; cin>>p;
		if(p<=a) ct[0]++;
		else if(p<=b) ct[1]++;
		else ct[2]++;
	}
	cout<<min({ct[0],ct[1],ct[2]})<<"\n";
	return 0;
}