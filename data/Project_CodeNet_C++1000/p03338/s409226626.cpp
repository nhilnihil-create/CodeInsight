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

void solve(int test_case) {//222
	int n;
	cin>>n;
	string s;
	cin>>s;
	int mcnt=0;
	REP(i,1,n-2) {
		unordered_map<char,int> a,b;
		REP(j,0,i-1)a[s[j]]++;
		REP(j,i,n-1)b[s[j]]++;
		int cnt =0;
		for(auto c:a) {
			if(b.count(c.F))cnt++;
		}
		mcnt=max(cnt,mcnt);
	}
	cout<<mcnt;
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
