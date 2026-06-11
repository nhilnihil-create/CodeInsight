/*
ID: anonymo14
TASK: wormhole
LANG: C++                 
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vpii;

#define F first
#define S second
#define PU push
#define PUF push_front
#define PUB push_back
#define PO pop
#define POF pop_front
#define POB pop_back

#define REP(i,a,b) for(int i=a; i<=b; i++)

#define MOD 1000000007

void solve(int test_case) {//213
	int n,h;
	cin>>n>>h;
	vi a(n),b(n);
	int mxa = 0;
	REP(i,0,n-1)cin>>a[i]>>b[i],mxa=max(mxa,a[i]);
	sort(b.begin(),b.end());
	int ipos = upper_bound(b.begin(),b.end(),mxa) - b.begin();
	int cnt = 0;
	for(int i=n-1;i>=ipos;i--) {
		h-=b[i];
		cnt++;
		if(h<=0)break;
	}
	if(h>0) cnt+=ceil((double)h/(double)mxa);
	cout<<cnt;
}

int main() {
	
	////// FILE BASED IO////
	//freopen("wormhole.in", "r", stdin);
	//freopen("wormhole.out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
