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

signed main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<int> l(n);
	for(int i=0;i<n;i++) cin>>l[i];
	sort(all(l));
	int sum=0;
	for(int i=0;i+1<n;i++) sum+=l[i];
	cout<<(l[n-1]<sum?"Yes":"No");
	re 0;
}