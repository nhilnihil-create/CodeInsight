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

void solve(int test_case) {//224
	int n,k;
	unordered_map<int,int> s;
	cin>>n>>k;
	REP(i,1,n) {
		int val;
		cin>>val;
		s[val]++;
	}
	vpii arr;
	arr.reserve((int)s.size());
	for(auto a:s) {
		arr.PUB({a.S,a.F});
	}
	sort(arr.begin(),arr.end());
	int kn = s.size();
	int cnt = 0;
	int i=0;
	while(kn>k) {
		kn--;
		cnt+=arr[i++].F;
	}
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
