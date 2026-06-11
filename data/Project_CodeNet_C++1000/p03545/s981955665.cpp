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
	int val;
	cin>>val;
	int d= val%10, c = (val/10)%10, b= (val/100)%10, a=(val/1000)%10;
	if(a+b+c+d==7) {
		cout<<a<<"+"<<b<<"+"<<c<<"+"<<d<<"=7";
	} else if(a-b+c+d==7) {
		cout<<a<<"-"<<b<<"+"<<c<<"+"<<d<<"=7";
	} else if(a+b-c+d==7) {
		cout<<a<<"+"<<b<<"-"<<c<<"+"<<d<<"=7";
	} else if(a+b+c-d==7) {
		cout<<a<<"+"<<b<<"+"<<c<<"-"<<d<<"=7";
	} else if(a-b-c+d==7) {
		cout<<a<<"-"<<b<<"-"<<c<<"+"<<d<<"=7";
	} else if(a+b-c-d==7) {
		cout<<a<<"+"<<b<<"-"<<c<<"-"<<d<<"=7";
	} else if(a-b+c-d==7) {
		cout<<a<<"-"<<b<<"+"<<c<<"-"<<d<<"=7";
	} else if(a-b-c-d==7) {
		cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<"=7";
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
