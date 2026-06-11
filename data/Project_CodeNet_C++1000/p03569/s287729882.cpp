#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 998244353
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
signed main(){
	string st;
	cin>>st;
	int lef = 0, rig = st.size() - 1, ans = 0;
	while( lef < rig ){
		int lct = 0, rct = 0;
		while( st[lef] == 'x' && lef <= st.size()-1 ){
			lct ++ ;
			lef ++ ;
		}
		while( st[rig] == 'x' && rig >= 0 ){
			rct ++ ;
			rig -- ;
		}
		if( st[lef] != st[rig] ){
			cout<<-1<<endl;
			return 0;
		}
		else if ( lef <= rig ){
			ans += abs( rct - lct );
		}
		lef++; rig--;
	}
	cout<<ans<<endl;
	return 0;
}