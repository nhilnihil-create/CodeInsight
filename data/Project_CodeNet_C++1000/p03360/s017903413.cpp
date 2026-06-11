#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
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
	int a[3],k;
	cin>>a[0]>>a[1]>>a[2]>>k;
	sort(a,a+3);
	while(k--) a[2]*=2;
	cout<<a[0]+a[1]+a[2];
	re 0;
}