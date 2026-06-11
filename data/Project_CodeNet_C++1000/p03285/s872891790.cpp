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
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int n;
signed main(){
	ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	rep(i,0,n)
		rep(j,0,n)
			if(i*4+j*7==n){
				cout<<"Yes";
				re 0;
			}
	cout<<"No";
	re 0;
}