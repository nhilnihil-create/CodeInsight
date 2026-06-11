#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define all(x) (x).begin(),(x).end()

int main(){
	int n,k; cin>>n>>k;
	vector<int> v(n);
	rep(i,n){
		int a; cin>>a; v[a-1]++;
	}
	sort(all(v));
	v.erase(remove(v.begin(),v.end(),0),v.end());
	int r=v.size();
	if(r<=k) cout<<0<<endl;
	else{
		int j=r-k, ans=0;
		rep(i,j) ans+=v[i];
		cout<<ans<<endl;
	}
}