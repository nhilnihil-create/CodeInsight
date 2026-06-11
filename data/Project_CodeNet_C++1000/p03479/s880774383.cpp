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
int l,r;
int ans,a;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>l>>r;
	a=l;
	while(1){
		ans++;
		a*=2;
		if(a>r) break;	
	}
	cout<<ans;
	re 0;
}