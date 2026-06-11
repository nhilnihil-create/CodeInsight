// #include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<math.h>
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

vector<pair<int,int>> adj[30]; 
void solve(){
	int l ;cin>>l; 
	int n=1; 
	while((1<<n)<=l) n++; 
	int start[30]={0}; 
	int m=0; 
	for(int i=1;i<n;i++){
		adj[i].push_back({i+1,1<<(n-i-1)}); 
		start[n-i-1]=i; 
		adj[i].push_back({i+1,0}); 
		m+=2; 
	}
	int len=1<<(n-1); 
	for(int i=n-2;i>=0;i--){
		if( (1<<i & l ) > 0){
			adj[1].push_back({ (i>=1? start[i-1]:n) , len}); 
			len^=(1<<i); 
			m++; 
		}
	}
	cout<<n<<" "<<m<<endl; 
	for(int i=1;i<=n;i++){
		for(auto p:adj[i]){
			cout<<i<<" "<<p.first<<" "<<p.second<<endl; 	
		}
	}
}


int main(){
	// clock_t beg=clock(); 
	fast_io; 
    cout << fixed << setprecision(13); 
	solve(); 	
	// clock_t end=clock(); 
	// fprintf(stderr, "%lf\n", (double)(end-beg)/(CLOCKS_PER_SEC));
}