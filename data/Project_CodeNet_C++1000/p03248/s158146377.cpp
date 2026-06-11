#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define ff first 
#define ss second
#define mod 1000000007
#define lim 100005
#define nfs_mw ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


int main()
{
	// nfs_mw;
	int i,u,n,rsz,root; string s;
	cin>>s;
	n = s.size();
	
	if((s[0] == '0') || (s[n-1] == '1')){
		cout<<(-1)<<"\n";
		return 0;
	}

	for(i=0; i<n/2; i++) if(s[i] != s[n-i-2]) {
		cout<<(-1)<<"\n";
		return 0;
	}
	
	root = u = 1;
	rsz = n - 1;

	for(i=(n/2); i>0; i--)
		if(s[i-1] == '1'){
			rsz -= i;
			while(rsz--)
				cout<<root<<" "<<(++u)<<"\n";
			cout<<root<<" "<<(++u)<<"\n";
			root = u;
			rsz  = i-1;
		}
}