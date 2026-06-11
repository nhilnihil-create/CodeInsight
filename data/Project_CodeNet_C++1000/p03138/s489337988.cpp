#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <functional>
#include <iomanip>
#include <bitset>

using namespace std;
#define     loop(n,i,a)     for(int i=a;i<n;i++)
#define     all(arr,n)      arr,arr+n
#define     allv(v)         (v).begin(),(v).end()
#define     rallv(v)        (v).rbegin(),(v).rend()
#define     m_p             make_pair
#define     ll              long long
#define     vi              vector<int>
#define     vll             vector<ll>
#define     sz(x)           (int)x.size()
#define     pb              push_back
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
ll power(ll x, ll y)
{
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
int main() {
	ll n,k;cin>>n>>k;
	ll arr[n],freq[64]={};
	loop(n,i,0)cin>>arr[i];
	loop(n,i,0){
		loop(64,j,0){
			if(arr[i]&power(2,j))
				freq[j]++;
		}
	}
	ll res=0;
	for(int i=40;i>=0;i--){
		ll p=power(2,i);
		if(freq[i]*2<n&&p<=k){
			k-=p;
			res+=(n-freq[i])*p;
		}
		else
			res+=freq[i]*p;
	}
	cout<<res<<endl;
	return 0;
}

