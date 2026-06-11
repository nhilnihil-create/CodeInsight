#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,h,w,ret=0; cin>>n>>h>>w;
	for (int i=0; i<n; i++) {
		int a,b; cin>>a>>b;
		if(a>=h&&b>=w) ret++;
	}
	cout<<ret<<"\n";
	return 0;
}