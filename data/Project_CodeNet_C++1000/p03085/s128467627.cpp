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

int a[maxn],b[maxn];

int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
		char a;
		cin >> a;
		if (a=='A') cout << 'T' << endl;
		else if (a=='T') cout << 'A' << endl;
		else if (a=='G') cout << 'C' << endl;
		else if (a=='C') cout << 'G' << endl;
		return 0;
}
