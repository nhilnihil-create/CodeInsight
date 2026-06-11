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
	vi cs(26,1);
	string s;
	cin>>s;
	for(char c:s)cs[c-'a']--;
	char req = '.';
	REP(i,0,25)if(cs[i]){req=i+'a';break;}
	if(req!='.') {
		s.PUB(req);
		cout<<s;
		return;
	}
	while(!s.empty()) {
		char last = s.back();
		s.pop_back();
		int ch = last-'a';
		REP(i,ch+1,25) {
			if(cs[i]) {
				s.PUB(i+'a');
				cout<<s;
				return;
			}
		}
		cs[ch]=1;
	}
	cout<<-1;
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
