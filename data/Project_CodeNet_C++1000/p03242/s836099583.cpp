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
	string n;
	cin>>n;
	for(int i=0;i<3;i++){
		if(n[i]=='9') cout<<1;
		if(n[i]=='1') cout<<9;
	}
	re 0;
}