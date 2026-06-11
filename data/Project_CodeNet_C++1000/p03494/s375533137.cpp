#include<iostream>
#include<cstring>
#include<cmath>
#include <vector> 

 
#define fastio()                ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll                      long long int
#define ull                     unsigned long long int
#define inp(n)                  ll n; cin >> n
#define inpc(c)                 char c; cin >> c
#define inps(s)                 string s; cin >> s
#define print(x)                cout << x << " "
#define nl                      cout << '\n'
#define pyes                    cout << "YES"
#define pno                     cout << "NO"
#define fr(i,a,b)               for(ll i=a; i<b; ++i)
#define frrev(i,b,a)            for(ll i=b; i<=a; --i)
#define strrev(s)               reverse(s.begin(), s.end())
#define pb(x)                   push_back(x)
#define vin(A, n)               vector<ll> A; fr(i,0,n){ ll x; cin >> x; A.pb(x); }
#define vinc(A, n)              vector<char> A; fr(i,0,n){ char x; cin >> x; A.pb(x); }
#define vpairin(A, n, t1, t2)   vector<pair<t1,t2> > A; fr(i,0,n) {t1 x; t2 y; cin >> x >> y; A.pb(make_pair(x,y));}
#define srt(A)                  sort(A.begin(), A.end())
#define vout(A, n)              fr(i,0,n){ print(A[i]); }
#define vpairout(A, n)          fr(i,0,n){ print(A[i].first); print(A[i].second); nl; }
 
using namespace std;

void solve()
{
	inp(n);
	int min = 1000000;
	for (int i = 0; i< n; i++)
	{
		int temp;
		cin >> temp;
		if (temp%2 == 0)
		{
			int temp2 = 0;
			while(temp%2 == 0)
			{
				temp2++;
				temp = temp/2;
			}
			if (temp2 < min)
				min = temp2;
		}
		else
		{
			min = 0;
		}
		
	}
	if (min == 1000000)
	{
		cout << "0";
	}
	else
	{
		cout << min;
	}
	


}
 
int main()
{
 
   fastio();
   solve();
   return 0;
}
 