#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
using ll = long long int;
using pi=pair<int,int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

constexpr int INF = 1 << 30;  // 1e9
constexpr ll INFL = 1l << 60; // 1e18
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define RANGE(i, a, b) for (int i = (a); i <= (b); i++)
#define RANGER(i, a, b) for (int i = (b); i >= (a); i--)
#define REP(i, n) FOR(i, 0, (n))
#define REPR(i, n) FORR(i, 0, (n))

#define EVAL 1

#ifdef EVAL
#define LOG(x) ;
#else
#define LOG(x) cerr << #x << ": " << (x) << endl;
#endif

vpi A=vpi(2e5);
int N;
void solve() {
	cin>>N;
	REP(i,N) {
		A[i].first=i;
		scanf("%d", &A[i].second);
	}
	sort(&A[0],&A[N],[](auto& a, auto& b){return a.second<b.second;});
	int ans=0,ln=0,pvi=INF;
	REP(i,N){
		if(pvi<A[i].first){
			ln++;
		}else{
			ln=1;
		}
		pvi=A[i].first;
		ans=max(ans,ln);
		LOG(ln)
	}
	cout<<N-ans<<endl;
	//*
	REP(i,N){
		LOG(A[i].first);
		LOG(A[i].second);
	}
	//*/
}

int main() {
	solve();
	return 0;
}