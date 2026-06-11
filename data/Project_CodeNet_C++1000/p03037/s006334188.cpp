#include<bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define all(x) (x).begin() (x).end()
#define rall(x) (x).rbegin() (x).rend()
typedef long long ll;

int main(){
	int n,m; cin>>n>>m;
	int i=-1, j=1e9;
	while(m--){
		int x, y;
		cin>>x>>y;
		i=max(i, x);
		j=min(j, y);
	}	
	int ans = (j-i)+1;
	if(ans<=0)cout<<0<<endl;
	else cout<<ans<<endl;
}
