/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll       long long
#define ull       unsigned long long
#define  si(x)   scanf("%d", &x)
#define  sll(x)   scanf("%lld", &x)
#define  sd(x)   scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100000
#define maxn 	  200002
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007



int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
	    string s;
	    cin >> s;
	    int ans = 753;
	    for (int i=0 ; i<(int)s.length()-2 ; i++)
	    {
			string t = s.substr(i,3);
			int x = 0;
			for (int j=0 ; j<3 ; j++)
			{
				x*=10;
				x+=t.at(j)-'0';
			}
			ans = min(ans,abs(753-x));
		}
		cout << ans << endl;
		return 0;
}
