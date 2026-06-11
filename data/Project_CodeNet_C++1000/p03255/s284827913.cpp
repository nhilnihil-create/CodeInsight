#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
#include <complex>
#include <cmath>
#include <array>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=200050;
//ここまでテンプレ
int main(){
	ull N,X;
	cin>>N>>X;
	vull x;
	for(int i=0;i<N;i++){
		ull a;
		cin>>a;
		x.pb(a);
	}
	for(int i=1;i<N;i++)
		x[i]+=x[i-1];
	reverse(x.begin(),x.end());
	ull ans=18446744073709551615LL;
	for(ull K=1;K<=N;K++){
		ull a=3,temp=5*x[0];
		for(ull i=K;i<N;i+=K)
			temp+=2*x[i];
		if(K<N)
			temp-=2*x[K];
		ans=min(ans,temp+(K+N)*X);
	}
	cout<<ans<<endl;
}