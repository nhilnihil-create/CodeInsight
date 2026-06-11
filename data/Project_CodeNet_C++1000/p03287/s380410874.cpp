#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=100100100100100;

int main(){
	ll n,m;
	cin>>n>>m;
	map<ll,ll> mp;
	ll a=0;
	mp[0]=1;
	ll ans=0;
	for(int i=0;i<n;i++){
		ll aa;
		cin>>aa;
		a+=aa;
		a%=m;
		if(mp.count(a)==0){
			mp[a]=1; 
			continue;
		}
		ans+=mp[a];
		mp[a]++;
	}
	cout<<ans<<endl;
}