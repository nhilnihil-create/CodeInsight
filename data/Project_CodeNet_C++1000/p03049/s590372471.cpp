#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define pi 3.141592653589793238462643383279502884197
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n;
	int a=0,b=0,ab=0;
	cin>>n;
	int ans = 0;
	for(int i=0;i<n;i++){
		string st;
		cin>>st;
		if( st[0] == 'B' && st[st.size()-1] == 'A' )ab++;
		else if( st[0] == 'B' ) b++;
		else if( st[st.size()-1] == 'A' ) a++;
		for(int j=0;j<st.size()-1;j++){
			if( st[j] == 'A' && st[j+1] =='B' ) ans++;
		}
	}
	//cout<<a<<b<<ab<<endl;
	if( a > 0 && b > 0 ){
		ans += ab+1;
		a--; b--;
	}
	else if( a > 0 ){
		ans += ab;
		a--;
	}
	else if( b > 0 ){
		ans += ab;
		b--;
	}
	else {
		ans += max( ab-1, 0LL );
	}
	ans += min(a,b);
	cout<<ans<<endl;
	return 0;
}