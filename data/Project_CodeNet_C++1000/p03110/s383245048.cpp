#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
double ans;
int n;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
		double x;
		string s;
		cin>>x>>s;
		if(s=="BTC") x*=380000;
		ans+=x; 
	}
	cout<<ans;
	re 0;
}