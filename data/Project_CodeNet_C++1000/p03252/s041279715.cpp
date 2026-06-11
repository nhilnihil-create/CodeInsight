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

void solve(int test_case) {//221
	string a,b;
	cin>>a>>b;
	unordered_map<char,char> m,n;
	REP(i,0,(int)a.length()-1) {
		if(m.count(a[i])==1||n.count(b[i])==1) {
			if(m[a[i]]!=b[i]||n[b[i]]!=a[i]) {
				cout<<"No";
				return;
			}
		} else {
			m[a[i]]=b[i];
			n[b[i]]=a[i];
		}
	}
	cout<<"Yes";
	
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
