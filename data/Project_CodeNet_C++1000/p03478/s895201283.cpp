#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int n,a,b;
int ans;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		int sum=0,x=i;
		while(x){
			sum+=x%10;
			x/=10;
		}
		if(sum>=a&&sum<=b) ans+=i;
	}
	cout<<ans;
	re 0;
}