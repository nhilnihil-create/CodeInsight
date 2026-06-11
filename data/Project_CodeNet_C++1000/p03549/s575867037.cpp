#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n,m; 
	cin>>n>>m; 
	int p = 1;
	for(int i=1;i<=m;i++)p*=2;
	int ans = p*(n*100+m*1800);
	cout<<ans<<endl;
	return 0;
}