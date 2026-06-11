#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	if(s[n-1]!='0' || s[0]!='1'){
		cout<<-1<<endl;
		return;
	}
	fr(i,0,n/2){
		if(s[i]!=s[n-1-i-1]){
			cout<<-1<<endl;
			return;
		}
	}
	vpii edges;
	edges.pb({1,2});
	int par=0;
	fr(i,1,n-1){
		edges.pb({par+1,i+2});
		if(s[i]=='1'){
			par=i+1;
		}
	}
	for(auto e: edges){
		cout<<e.first<<" "<<e.second<<endl;
	}
	return;
}

int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}