/*** Author: Dhruv Rastogi ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(sdk) sdk.begin(),sdk.end()
#define mll map<ll,ll>
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repd(i,a,b) for(ll i=a;i>=b;--i)
#define mp make_pair
#define hell 1000000007
#define endl '\n'
#define vvll vector<vector<ll> >
#define vll vector<ll>
#define mint map<int,int> 
#define int long long
#define sz(x) (int)x.size()
#define sll set<int>
#define pll pair<int,int>

int vis[(int)1e6+2];
void solve(){  
	int n;
	cin>>n;
	rep(i,1,1000){
		vis[i*(i+1)/2]=i;
	}
	if(!vis[n]){
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
	vll v[2000];
	int num=1;
	rep(i,1,vis[n]+2){
		rep(j,i+1,vis[n]+2){
			v[i].pb(num);
			v[j].pb(num);
			++num;
		}
	}
	cout<<vis[n]+1<<endl;
	rep(i,1,vis[n]+2){
		cout<<sz(v[i])<<' ';
		for(auto j:v[i]) cout<<j<<' ';
		cout<<endl;
	}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}