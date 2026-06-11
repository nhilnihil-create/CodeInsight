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

void solve(int test_case) {
	int n;
	cin>>n;
	vi ans(100001,100001);ans[0]=0;
	int arr[12] = {1,6,9,36,81,216,729,1296,6561,7776,46656,59049};
	for(int i=1;i<=100001;i++) {
		for(int j=0;j<12;j++) {
			if(i-arr[j]>=0) {
				ans[i]=min(ans[i],ans[i-arr[j]]+1);
			}
		}
	}
	cout<<ans[n];
}//sum-nsum=n*b;

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
