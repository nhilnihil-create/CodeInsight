#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=200100,powN=pow(2,ceil(log2(N)));
ll dp[N];
int h[N],a[N],n;
ll tree[2*powN];

ll update(int l,int r,int idx,int tl,int tr,ll d){
	if(l==tl&&r==tr)return tree[idx]=d; // got'em
	if(l>=tr||r<=tl)return tree[idx]; // out
	int md=(tl+tr)/2;
	return tree[idx]=max(update(l,r,2*idx,tl,md,d),update(l,r,2*idx+1,md,tr,d));
}

ll query(int l,int r,int idx,int tl,int tr){
	if(l<=tl&&r>=tr)return tree[idx]; // in
	if(l>=tr||r<=tl)return 0; // out
	int md=(tl+tr)/2;
	return max(query(l,r,2*idx,tl,md),query(l,r,2*idx+1,md,tr));
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>h[i];
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i){
		ll mx=query(0,h[i],1,0,powN);
		update(h[i]-1,h[i],1,0,powN,mx+a[i]);
	}
	ll res=0;
	for(int i=powN;i-powN<n;++i)res=max(res,tree[i]);
	cout<<res<<endl;
}
