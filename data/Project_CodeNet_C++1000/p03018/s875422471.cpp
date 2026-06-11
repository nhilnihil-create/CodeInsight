#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
signed main(){
	string str;
	cin>>str;
	int ans = 0;
	int n = str.size();
	int ac = 0;
	for(int i=0;i<n-1;i++){
		if( str[i] == 'A' ){
			ac ++ ;
		}
		else if ( str[i] == 'B' && str[i+1] == 'C' ){
			ans += ac;
			i++;
		}
		else{
			ac = 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}