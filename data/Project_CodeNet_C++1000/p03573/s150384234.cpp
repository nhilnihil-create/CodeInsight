#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int a[3];
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[0]!=a[1]) cout<<a[0];
	else cout<<a[2];
	re 0;
}