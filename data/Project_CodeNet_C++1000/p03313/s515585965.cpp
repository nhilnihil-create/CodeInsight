#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef pair< int, int > Pi;
typedef pair< long long, long long > P;
typedef pair< long long, P > PP;
typedef pair< P, P > PPP;

const double DINF = 5e14, eps = 1e-10;
const long long MOD = 1e9 + 7, INF = 5e18;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()

int n,a[1<<18];
P dp1[1<<18];
int dp2[1<<18];

void input(){
	cin>>n;
	for(int i=0;i<(1<<n);i++){
		cin>>a[i];
	}
	return;
}

void solve(){
	dp1[0]=P(0,0);
	for(int i=1;i<(1<<n);i++){
		vector<int>v;
		v.eb(i);
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			v.eb(dp1[i-(1<<j)].fr);
			v.eb(dp1[i-(1<<j)].sc);
		}
		sort(ALL(v));
		v.erase(unique(ALL(v)),v.end());
		sort(ALL(v),[&](int c,int d){return a[c]>a[d];});
		dp1[i].fr=v[0];
		dp1[i].sc=v[1];
	}
	for(int i=1;i<(1<<n);i++){
		dp2[i]=a[dp1[i].fr]+a[dp1[i].sc];
	}
	for(int i=1;i<(1<<n);i++){
		dp2[i]=max(dp2[i],dp2[i-1]);
		cout<<max(dp2[i],dp2[i-1])<<endl;
	}
	return;
}

int main() {
	input();
	solve();
	return 0;
}
