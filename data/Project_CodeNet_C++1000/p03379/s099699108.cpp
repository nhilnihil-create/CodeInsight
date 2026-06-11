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
int n,x[200005],a[200005];
map<int,int> pos;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
		a[i]=x[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
	for(int i=0;i<n;i++) pos[a[i]]=i;
	int l=n/2-1;
	for(int i=0;i<n;i++){
		if(pos[x[i]]<=l) cout<<a[l+1]<<"\n";
		else cout<<a[l]<<"\n";
	}
	re 0;
}