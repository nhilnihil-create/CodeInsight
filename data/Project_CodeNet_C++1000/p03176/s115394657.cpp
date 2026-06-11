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

const int N=2e5+5;
int h[N];
ll tree[4*N],a[N];
ll mx;

void update(int v,int tl,int tr,int pos){
	if(tl==tr){
		tree[v]=mx;
		return;
	}
	int tm=(tl+tr)/2;
	if(tm>=pos){
		update(v*2,tl,tm,pos);
	}
	else{
		update(v*2 +1,tm+1,tr,pos);
	}
	tree[v]=max(tree[v*2],tree[v*2 +1]);
}

ll getmax(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l <= tl && tr <= r){
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return max(getmax(v*2, tl, tm, l, min(r, tm)), getmax(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve(){
	int n;
	cin>>n;
	fr(i,0,n){
		cin>>h[i];
	}
	fr(i,0,n){
		cin>>a[i];
	}
	ll ans=0;
	fr(i,0,n){
		mx=getmax(1,1,n,1,h[i])+a[i];
		update(1,1,n,h[i]);
		ans=max(mx,ans);
	}
	cout<<ans<<endl;
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