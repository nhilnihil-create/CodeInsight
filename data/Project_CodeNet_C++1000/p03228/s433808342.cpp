#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll a,b,k; cin>>a>>b>>k;
	for (int i=0; i<k; i++) {
		if(i%2) swap(a,b);
		if(a%2) a--;
		a/=2;
		b+=a;
		if(i%2) swap(a,b);
	}
	cout<<a<<" "<<b<<"\n";
	return 0;
}