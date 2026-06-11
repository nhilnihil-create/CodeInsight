#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<iterator>
#include<cmath>
#include<string>
#include<algorithm>
#include<sstream>
#include<queue>
#include<list>
#include<deque>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<chrono>


/*  auto start = high_resolution_clock::now();
auto stop = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(stop - start);
pr(duration.count());    */


#define FastIO      ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define pb          push_back
#define siz         100009
#define mp          make_pair
#define ll          long long int
#define fileout     freopen("output.txt","w",stdout)
#define filein      freopen("input.txt","r",stdin)
#define pi          acos(-1.0)
#define all(x)      x.begin(),x.end()
#define ull		    unsigned long long int
#define m(a)	    memset(a,0,sizeof(a))
#define f(i,n)	    for(ll i=0;i<n;i++)
#define sc(a)	    scanf("%lld",&a)
#define pr(a)	    printf("%lld\n",a)
const ll inf = 5000000000000000;
ll in = 1000000000000000000;
using namespace std;
ll gcd(ll a, ll b)
{
	if (a == 0)
		return b;
	else
		return gcd(b % a, a);
}
int main()
{
	FastIO;
	ll a,b,d, co, t, i, j, k, n,r;
	cin >> n;
	vector<ll>v, dif;
	f(i, n)
	{
		cin >> a;
		v.push_back(a);
	}
	sort(all(v));
	ll ans = v[0];
	for(i=0;i<v.size();i++)
	{
		if (i)
		{
			ans = gcd(ans, v[i]);
			if (ans == 1)
				break;
		}
	}
	cout << ans << endl;
	return 0;
}
