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

void solve(int test_case) {//233
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	vector<int> arr;
	REP(i,0,n-2) {
		if(s[i]=='A'&&s[i+1]=='C'){
			arr.PUB(i);
			i++;
		}
	}
	
	while(q--) {
		int l,r;
		cin>>l>>r;
		cout<<upper_bound(arr.begin(),arr.end(),r-2)-lower_bound(arr.begin(),arr.end(),l-1)<<endl;
	}
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
