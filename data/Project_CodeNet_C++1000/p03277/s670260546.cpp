#include <bits/stdc++.h>
// #include<iostream>
// #include<iomanip>
// #include<set>
// #include<vector>
// #include<map>
// #include<queue>
// #include<stack>
// #include<algorithm>
// #include<math.h>
using namespace std; 

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef long long ll; 
typedef long double ld; 
#define prarr(a,n) cerr<<#a<<" : ";for(ll i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define prmat(mat,row,col) cerr<<#mat<<" :\n";for(ll i=0;i<row;i++) {for(ll j=0;j<col;j++) cerr<<mat[i][j]<<"\t";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
#define all(a) a.begin(),a.end()
#define sz(x) ((int)x.size())
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(NULL); cin.tie(NULL)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {ll idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
template <class T> void prall(T a) { prc(all(a)); }
const int inf=1000*1000*1000+9; 
const ll infl=1ll*inf*inf; 
const int mod=1000*1000*1000+7;  

// ----------------------------------------------------------------------------	-------------- 

const int nax=2e5+5; 
const int offset=1e5+2; 
int tr[nax<<2]; 

void up(int p, int l, int r, int i){
	if(i<l || i> r) return;
	if(l==r){
		tr[p]+=1; 
		return;
	}
	int m=(l+r)>>1; 
	up(p<<1, l,m,i); 
	up(p<<1|1, m+1, r, i); 
	tr[p]=tr[p<<1]+tr[p<<1|1]; 
}
int qq(int p, int l, int r, int i, int j){
	if(r<i || l>j) return 0; 
	else if ( i<= l && r <= j) return tr[p]; 
	int m=(l+r)>>1; 
	return qq(p<<1, l,m,i,j)+ qq(p<<1|1, m+1, r, i,j); 
}

void solve(){
	int n; cin>>n; 
	vector<int> a(n); 
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	int lo=0, hi=mod; 
	ll amt=1ll* n*(n+1)/2; 
	while((hi-lo)>1){
		int x=(hi+lo)/2; 
		memset(tr,0,sizeof(tr));  
		vector<int> v, pre(n+1); 
		v.push_back(0); 
		up(1,0,nax-1,0+offset); 
		ll cnt=0; 
		for(int i=0;i<n;i++){
			if(a[i]<=x) v.push_back(1); 
			else v.push_back(-1); 
			pre[i+1]+=pre[i]+v[i+1]; 
			cnt+=qq(1,0,nax-1,0,pre[i+1]-1+offset); 
			up(1,0,nax-1,pre[i+1]+offset); 
		}
		if(cnt > amt/2){
			hi=x; 	
		}
		else {
			lo=x; 
		}
	}
	cout<<hi<<endl; 
}


int main(){
	// clock_t beg=clock(); 
	fast_io; 
    cout << fixed << setprecision(13); 
	solve(); 	
	// clock_t end=clock(); 
	// fprintf(stderr, "%lf\n", (double)(end-beg)/(CLOCKS_PER_SEC));
}