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
	if((n[0]==n[1]&&n[1]==n[2])||(n[1]==n[2]&&n[2]==n[3])) cout<<"Yes";
	else cout<<"No";
	re 0;
}