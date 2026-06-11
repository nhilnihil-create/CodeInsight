/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll       long long
#define ull       unsigned long long
#define  sci(x)   scanf("%d", &x)
#define  scl(x)   scanf("%lld", &x)
#define  scd(x)   scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100000
#define maxn 	  200002
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000


int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
		int n,q;
		cin >> n >> q;
		string s;
		cin >> s;
		vector<int> a(maxn);
		for (int i=0 ; i<n ; i++)
		{
			if (i+1<n && s[i]=='A' && s[i+1]=='C')
			a[i+1]=a[i]+1;
			else
			a[i+1]=a[i];
		}
		for (int i=0 ; i<q ; i++)
		{
			int l,r;
			cin >> l >> r;
			l--;
			r--;
			
			cout << a[r]-a[l] << endl;
			
		}
		
		return 0;
}
