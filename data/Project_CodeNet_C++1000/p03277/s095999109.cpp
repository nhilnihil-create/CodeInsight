#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define INF 1000000
#define MID (l+r)/2
#define ll long long


int b[10*INF];
ll seg[100*INF];

ll query(int rl, int rr, int l=0, int r=INF-1, int ind=1){
	if(rl<=l && r<=rr) return seg[ind];
	else if(rl>r || l>rr) return 0;
	return query(rl, rr, l, MID, ind*2) + query(rl,rr,MID+1,r,ind*2+1);
}

void update(int x, int l=0, int r=INF-1, int ind=1){
	if(l==r && l==x){ seg[ind]++; return;}
	if(x<l || x>r) return;
	update(x,l,MID,ind*2);
	update(x,MID+1,r,ind*2+1);
	seg[ind] = seg[ind*2] + seg[ind*2+1];
}


int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	ll l=0, r=2000000000;
	ll m;
	ll anss=0;
	while(l<=r){
		m = MID;
		ll ans=0, s = n+1;
		memset(seg, 0, 4*INF * sizeof(1ll));
		update(s);
		for(int i=0;i<n;i++){
			s += (a[i]>=m ? 1 : -1);
			ans+=query(0,s);
			update(s);
		}
		if(ans < (n*(n+1)+3)/4) r = m-1;
		else l = m+1, anss=m;
	}
	cout<<anss<<endl;
}
