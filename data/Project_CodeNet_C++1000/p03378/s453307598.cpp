#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
bool seen[105];
signed main(){
	ios_base::sync_with_stdio(0);
	int n,m,x;
	cin>>n>>m>>x;
	while(m--){
		int a;
		cin>>a;
		seen[a]=1;
	}
	int c1=0,c2=0;
	int cur=x;
	while(cur){
		cur--;
		if(seen[cur]) c1++;
	}
	cur=x;
	while(cur!=n){
		cur++;
		if(seen[cur]) c2++;
	}
	cout<<(c1<c2?c1:c2);
	re 0;
}