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

ull sol = 0;
char arr[5]={'M','A','R','C','H'};

void perm(unordered_map<char,ull> &ma, vector<char> &ch, int i=0) {
	if(ch.size()==3) {
		sol+=ma[ch[0]]*ma[ch[1]]*ma[ch[2]];
		return;
	}
	for(;i<5;i++) {
		if(ma[arr[i]]>0) {
			ch.PUB(arr[i]);
			perm(ma,ch, i+1);
			ch.POB();
		}
	}
}

void solve(int test_case) {
	int n;
	cin>>n;
	unordered_map<char,ull> ma;
	while(n--) {
		string s;
		cin>>s;
		ma[s[0]]++;
	}
	vector<char> ch;
	perm(ma, ch);
	cout<<sol;
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
