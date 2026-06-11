#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,ans=0;
	cin>>n;
	vi v(n),c(n);
	for(int &x:v) cin>>x;
	for(int &x:c) cin>>x;
	for(int i=0;i<(1<<n);++i){
		int x=0,y=0;
		for(int j=0;j<n;++j){
			if((i&(1<<j))){
				x+=v[j];
				y+=c[j];
			}
		}
		ans = max(ans,x-y);
	}
	cout<<ans<<endl;
	return 0;
}