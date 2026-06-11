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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if((abs(a-b)<=d&&abs(b-c)<=d)||abs(a-c)<=d) cout<<"Yes";
	else cout<<"No";
	re 0;
}