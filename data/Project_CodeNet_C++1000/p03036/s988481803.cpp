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

ll maxn = 1e18;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//#endif
	ll r,d,xi;
	cin>>r>>d>>xi;
	for(int i=0;i<10;++i){
		xi = r*xi-d;
		cout<<xi<<endl;
	}
	return 0;
}