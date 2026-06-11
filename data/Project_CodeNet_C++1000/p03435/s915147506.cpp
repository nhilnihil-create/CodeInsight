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

void solve(int test_case) {//227
	vector<vi> c(3,vi(3));
	for(auto &i:c)for(auto &j:i)cin>>j;
	int a1,a2,a3,b1,b2,b3;
	for(a1=0;a1<101;a1++) {
		b1=c[0][0]-a1;
		for(a2=0;a2<101;a2++){
			b2=c[1][1]-a2;
			for(a3=0;a3<101;a3++) {
				b3=c[2][2]-a3;
				if(c[0][1]==a1+b2&&c[0][2]==a1+b3&&c[1][0]==a2+b1&&c[1][2]==a2+b3&&c[2][0]==a3+b1&&c[2][1]==a3+b2){
					cout<<"Yes";
					return;
				}
			}
		}
	}
	cout<<"No";
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
