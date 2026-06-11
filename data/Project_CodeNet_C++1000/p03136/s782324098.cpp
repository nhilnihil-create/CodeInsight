/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define si(x)     scanf("%d", &x)
#define sll(x)    scanf("%lld", &x)
#define ssll(x,y)    scanf("%lld %lld", &x ,&y)
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100005
#define maxn 	  200002
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define vll(a)	  vector<ll>a
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "



int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
		ll n;
		sll(n);
		ll a[maxn];
		for (int i=0 ; i<n ; i++) sll(a[i]); 
		sort(a,a+n);
		ll sum = 0;
		for (int i=0 ; i<=n-2 ; i++) sum+=a[i];
	//	cerr << imie(sum) imie(a[n-1]);
		if(a[n-1]<sum) cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
}

