#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define all(x) (x).begin(),(x).end()

int main(){
	int n,k; cin>>n>>k;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	sort(all(v));
	int mx, mn, ans=1e9+7;
	rep(i,n-k+1){
		mn=v[i]; mx=v[k-1+i];
		ans=min(ans,mx-mn);
	}
	cout<<ans<<endl;
}