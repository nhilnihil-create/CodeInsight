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
	vi arr(n);
	for(int &i:arr)cin>>i;
	sort(arr.begin(),arr.end());
	while(arr.size()>1) {
		vi a;
		REP(i,1,(int)arr.size()-1) {
			int p = arr[i]%arr[0];
			if(p!=0)
			a.PUB(p);
		}
		a.PUB(arr[0]);
		sort(a.begin(),a.end());
		arr=a;
	}
	cout<<arr[0];
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
