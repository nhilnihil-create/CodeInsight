#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <iomanip>
#define rep(i, a, b) for (int(i) = (a); i < (b); i++)
using namespace std;

using ll = long long;

typedef pair<int, int> P;

const int INF = 100000000;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll MOD = 1000000007;

ll pow_mod(ll x, ll y, ll mod)
{
	ll ans=1;
	for(;y>0;y>>=1){
		if(y&1)(ans*=x)%=mod;
		(x*=x)%=mod;
	}
	return ans;
}

int n;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	//問題文中の添え字が0-indexか1-indexか確認!
	cin>>n;
	vector<P> a(1<<n);
	rep(i,0,1<<n){
		int b;
		cin>>b;
		a[i]=P(b,0);
	}
	vector<int> temp(4);
	rep(i,0,n){
		rep(j,0,1<<n){
			if((j>>i&1)){
				temp[0]=a[j].first;
				temp[1]=a[j].second;
				temp[2]=a[j^1<<i].first;
				temp[3]=a[j^1<<i].second;
				sort(temp.begin(),temp.end(),greater<int>());
				a[j]=P(temp[0],temp[1]);
			}
		}
	}
	vector<ll> maxa(1<<n);
	maxa[0]=a[0].first+a[0].second;
	rep(i,1,1<<n){
		maxa[i]=max(maxa[i-1],(ll)a[i].first+a[i].second);
		cout<<maxa[i]<<"\n";
	}
	return 0;
}