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

void solve(int test_case) {//228
	int n;
	cin>>n;
	unordered_map<int,int> a,b;
	bool flag = true;
	REP(i,1,n) {
		int val;
		cin>>val;
		if(flag)a[val]++;
		else b[val]++;
		flag=!flag;
	}
	int a1=0,a1v=0,a2=0;
	int b1=0,b1v=0,b2=0;
	for(auto p:a) {
		if(p.S>=a1) {
			//cerr<<p.F<<" "<<p.S<<" ";
			a2=max(a2,a1);
			a1=p.S;
			a1v=p.F;
		} else {
			a2=max(a2,p.S);
		}
	}
	for(auto p:b) {
		if(p.S>=b1) {
			//cerr<<p.F<<" "<<p.S<<" ";
			b2=max(b1,b2);
			b1=p.S;
			b1v=p.F;
		} else {
			b2=max(b2,p.S);
		}
	}
	if(a1v==b1v) {
		//cerr<<a1<<" "<<b1<<" "<<a1v<<" "<<b1v;
		cout<<min(max(0,n-b1-a2),max(0,n-a1-b2));
	} else {
		cout<<n-a1-b1;
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
