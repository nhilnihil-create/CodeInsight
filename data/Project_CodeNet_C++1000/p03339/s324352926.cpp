#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i, n) for(int i =0 ; i < n; ++i)
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define pii pair < int, int >
typedef vector<int> vi;
typedef  long long ll;
const int mod =1e9+7;
const int N = (int)2e5 + 5;

void solve(){
	int n; cin>>n;
	string s; cin>>s;
	int ans = 1e9;
	int p[n+1],t[n+1];
	p[0]=0,t[0]=0;
	rep(i,n){
		if(!i)p[i+1] = (s[i] == 'E'?1:0);
		else p[i+1] = p[i]+(s[i] == 'E');
	}
	for(int i = n-1;i >= 0;--i){
		if(i == n-1)t[i+1] = (s[i] == 'W'?1:0);
		else t[i+1] = t[i+2]+(s[i] == 'W');
	}
	for(int i = 1;i <= n;++i){
		if(i!=1 && i!=n)ans = min(ans,n-p[i-1]-1-t[i+1]);
		if(i==1)ans=min(ans,n-1-t[i+1]);
		if(i==n)ans=min(ans,n-1-p[i-1]);
	}
	cout<<ans;

}

int main(){
	Red;
	int t=1;
	//cin>>t;
	while(t--)
	solve();
	return 0;
}