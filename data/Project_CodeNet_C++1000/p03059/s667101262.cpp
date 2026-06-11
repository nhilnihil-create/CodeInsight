#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

const int maxn = 1e8;

vector<bool> sieve(maxn,1);

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a,b,t,at,ans=0;
	cin>>a>>b>>t; at=a;
	while(a<=t){
		ans+=b;
		a+=at;
	}
	cout<<ans<<endl;
	return 0;
}