/*  

    IITAPOORV094

/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
|                                        |
|   *******     *******     ********     |
|      |           |            |        |
|      |           |            |        |
|      |           |            |        |
|   *******     *******         |        |
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

*/
  // This will work only for g++ compiler. 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>



#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based

//short hand for usual tokens
#define pb push_back
#define fi first
#define se second

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())

//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())

// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())


using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;



ll solve(ll a[],ll b[],ll n)
{
	ll dp[n+1];
	map<ll ,ll>mp;
	dp[1]=b[1];
	mp[a[1]]=b[1];
	ll ans=0;
	forc(i,2,n)
	{
		auto it =mp.lower_bound(a[i]+1);
		dp[i]=b[i];
		if(it!=mp.begin())
		{
			it--;
			dp[i]=dp[i]+it->second;
		}
		mp[a[i]]=dp[i];
	    it=mp.upper_bound(a[i]);
		while(it!=mp.end()&&it->second<=dp[i])
		{
			auto temp=it;
			temp++;
			mp.erase(it);
			it=temp;
		}
	}
	forr1(i,n)
	{
		if(dp[i]>ans)
		{
			ans=dp[i];
		}
	}
	return(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    

    ll n;
    cin>>n;
    ll a[n+1];
    for1(i,n)
    {
    	cin>>a[i];
    }    
    ll b[n+1];
    for1(i,n)
    {
    	cin>>b[i];
    }
    cout<<solve(a,b,n);
    return 0;
}
