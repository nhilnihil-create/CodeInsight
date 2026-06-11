
// Problem : A - Two Abbreviations
// Contest : AtCoder Grand Contest 028
// URL : https://atcoder.jp/contests/agc028/tasks/agc028_a
// Memory Limit : 1024.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

//Dragon_warrior7(IITK)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl cout << '\n'
#define sor(x) sort(x.begin(), x.end())
#define rev(v) reverse(v.begin(), v.end())
#define lb(v, temp) lower_bound(v.begin(), v.end(), temp)
#define ub(v, temp) upper_bound(v.begin(), v.end(), temp)
#define fi first
#define se second
#define llmax 1000000000000000000
#define deb(x) cout << #x << " " << x << "\n"
#define pll pair<ll, ll> 
#define vll vector<ll> 
#define rub cout << "\n------------------------------------\n"
void read(vector<ll> &v)
{
	for (int i = 0; i < v.size(); i++)
		cin >> v[i];
}

void print(vector<ll> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}
ll n,m,a,b,temp,x,y;
string str;
set<ll> s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
   cin>>n>>m;
   string s,t;
   cin>>s>>t;
   rev(s);
   rev(t);
   s.pb('@');
   t.pb('@');
   rev(s);
   rev(t);
   if(n==m)
   {
      if(s==t)
      {
         cout<<n;
      }
      else
      cout<<-1;
      return 0;
   }
   if(s.size()>t.size())
   swap(s,t);
   n=s.size();
   m=t.size();
   n--;
   m--;
   for(int i=1;i<=n;i++)
   {
      if((m*(i-1))%n!=0)
      continue;
      if(s[i]!=t[(m*(i-1))/n+1])
      {cout<<-1;return 0;}
   }
   cout<<((m)*(n))/__gcd(m,n);
	
}