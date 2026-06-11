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
int ans;
signed main(){
	ios_base::sync_with_stdio(0);
	for(int i=0;i<4;i++){
		char c;
		cin>>c;
		if(c=='+') ans++;
		else ans--;
	}
	cout<<ans;
	re 0;
}