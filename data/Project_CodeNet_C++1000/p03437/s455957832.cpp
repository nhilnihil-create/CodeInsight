#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int x,y; cin>>x>>y;
	cout<<(x%y?x:-1)<<"\n";
	return 0;
}