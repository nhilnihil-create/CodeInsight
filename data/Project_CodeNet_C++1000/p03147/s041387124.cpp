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

void solve(int test_case) {
	int n;
	cin>>n;
	vi arr(n);
	for(int &i:arr)cin>>i;
	int cnt = 0;
	while(1) {
		bool set = false;
		int st = -1;
		int en = -1;
		int mi =INT_MAX;
		for(int i=0;i<n;i++) {
			if(!set&&arr[i]==0)continue;
			if(set&&arr[i]==0){break;}
			en =i;
			mi=min(arr[i],mi);
			if(!set){st = i;set=true;}
		}
		if(!set)break;
		for(;st<=en;st++)arr[st]-=mi;
		cnt+=mi;
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
