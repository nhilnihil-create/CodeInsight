#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	vector< pair<int, pair<int,int> > > fs;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		fs.pb( mp( a+b, mp(a,b) ) );
	}
	sort( fs.begin(), fs.end() );
	reverse( fs.begin(), fs.end() );
	int ans = 0;
	for(int i=0;i<n;i++){
		if( i % 2 == 0 ){
			ans += fs[i].second.first;
		}
		else{
			ans -= fs[i].second.second;
		}
	}
	cout<<ans<<endl;
	return 0;
}