#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
const int MOD=1e9+7;
int powmod(int a,int l, int md){a%=md; int res=1;while(l){if(l&1)res=res*a%md;l/=2;a=a*a%md;}return res;}
int binpow(int a,int l){int res=1;while(l){if(l&1)res=res*a;l/=2;a=a*a;}return res;}
int invmod(int a, int md){return powmod(a,md-2,md);}
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef vector<int> vi; typedef pair<int, int> ii; typedef vector< ii > vii;
#define pb push_back
int __set(int b, int i) {return b|(1LL<<i);} //set ith bit
int __unset(int b, int i) {return b&(~(1UL<<i));}
int __check(int b, int i) {return b&(1LL<<i);} //returns 0 if ith bit is 0
int mulmod(int a, int b, int md) {return (((a%md)*(b%md))%md+md)%md;}
int addmod(int a, int b, int md) {return ((a%md+b%md)%md+md)%md;}
int submod(int a, int b, int md) {return (((a%md-b%md)%md)+md)%md;}
int divmod(int a, int b, int md) {return mulmod(a, powmod(b, md-2, md), md);} //if md is prime;
const ll inf = 0xFFFFFFFFFFFFFFFL; //very large number
priority_queue<int, vector<int>, greater<int> > pq; //for min priority_queue
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int solve(vi& a) {
	int n=sz(a);
	int cnt=0,ret=0;
	for(int i = n-1; i >= 0; i--) {
		if(a[i]==1) ret+=cnt;
		else cnt++;
	}
	return ret;
}
signed main(void)
{
	IOS;
	string s; cin>>s;
	int n=s.length();
	int found=0,ans=0;
	vi ar;
	for(int i = 0; i < n; i++) {
		// cout<<i<<" "<<found<<endl;
		if(s[i]=='A') {
			if(found) ar.pb(1);
			else {
				ar.clear();
				ar.pb(1);
				found=1;
			}
			continue;
		}
		if(s[i]=='B') {
			if(i+1>=n) continue;
			if(s[i+1]=='C') {
				if(found) ar.pb(2);
				else {
					ar.clear();
					ar.pb(2);
					found=1;
				}
				i++;
			} else {
				ans += solve(ar);
				ar.clear();
				found=0;
			}
			continue;
		}
		if(s[i]=='C') {
			if(found) {
				ans += solve(ar);
				ar.clear();
				found=0;
			}
		}
	}
	// for(int i: ar) cout<<i<<" ";
	// 	cout<<endl;

	if(found && sz(ar)) ans += solve(ar);
	cout<<ans<<endl;
	return 0;
}