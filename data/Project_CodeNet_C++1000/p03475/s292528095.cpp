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

void solve(int test_case) {//227
	int n;
	cin>>n;
	vector<array<ll,3>> arr(n-1);
	REP(i,0,n-2) {
		ll a,b,c;
		cin>>a>>b>>c;
		arr[i]={a,b,c};
	}
	vll ans(n-1);
	REP(i,0,n-2) {
		ll last = 0;
		REP(j,i,n-2) {
			if(last>arr[j][1]){
				int req = (last)%arr[j][2];
				if(req!=0)req=arr[j][2]-req;
				last = last + req + arr[j][0];
			} else {
				last = arr[j][1] + arr[j][0];
			}
		}
		ans[i]=last;
	}
	REP(i,0,n-2)cout<<ans[i]<<"\n";
	cout<<0;
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
