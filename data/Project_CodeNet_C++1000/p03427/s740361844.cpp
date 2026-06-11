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

void solve(int test_case) {//209
	string s;
	cin>>s;
	bool n = true;
	for(char c:s)if(c!='9')n=0;
	int m=0;
	if(n) {
		m=9*s.length();
	} else {
		for(char c:s)m+=c-'0';
	}
	int beg = s[0]-'1';
	int ans = 0;
	ans+=9*((int)s.length()-1);
	ans+=beg;
	cout<<max(m,ans);
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
	//prefill();
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
