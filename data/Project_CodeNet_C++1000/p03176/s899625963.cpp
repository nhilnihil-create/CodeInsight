#include<bits/stdc++.h>
#define ll long long
#define f first
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define all(v) v.begin(),v.end()
#define mem(v,x) memset(v,x,sizeof(v))
#define ar array
#define N 200005

using namespace std;

ll bit[N];
void upd(int i, ll val){
    for(;i<N;i+=i&-i){
        bit[i] = max(bit[i], val);
    }
}
ll query(int i){
    ll val = 0;
    for(;i;i-=i&-i){
        val = max(val, bit[i]);
    }
    return val;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	int h[n];
    ll a[n];
	for(int i=0;i<n;i++){
        cin>>h[i];
	}
	for(int i=0;i<n;i++){
        cin>>a[i];
	}
	ll ans = 0, mx = 0;
	for(int i=0;i<n;i++){
        mx = query(h[i]) + a[i];
        ans = max(ans, mx);
        upd(h[i], mx);
	}
	cout<<ans;
	return 0;
}
