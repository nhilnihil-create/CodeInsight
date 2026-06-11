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
	string a,b;
	cin>>a>>b;
	vector<string> v;
	REP(i,0,(int)a.length()-(int)b.length()) {
		bool h = true;
		REP(j,0,(int)b.length()-1) {
			if(b[j]!=a[i+j]&&a[i+j]!='?') {
				h=0;
				break;
			}
		}
		if(h) {
			string tem = a;
			REP(j,0,(int)b.length()-1) {
				tem[i+j]=b[j];
			}
			REP(j,0,(int)a.length()-1){
				if(tem[j]=='?')tem[j]='a';
			}
			v.PUB(tem);
		}
	}
	if(v.size()>0){
		sort(v.begin(),v.end());
		cout<<v[0];
	} else
	cout<<"UNRESTORABLE";
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
