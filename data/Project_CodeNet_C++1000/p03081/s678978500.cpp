//Dragon_warrior7(IITK)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl cout << '\n'
#define sor(x) sort(x.begin(), x.end())
#define rev(v) reverse(v.begin(), v.end())
#define maxin(v) *max_element(v.begin(), v.end())
#define minin(v) *min_element(v.begin(), v.end())
#define sumall(vect) accumulate(vect.begin(), vect.end(), 0)
#define count(x, vect) count(vect.begin(), vect.end(), x)
#define lb(v, temp) lower_bound(v.begin(), v.end(), temp)
#define ub(v, temp) upper_bound(v.begin(), v.end(), temp)
#define fi first
#define se second
#define llmax 100000000000000000
#define deb(x) cout << #x << " " << x << "\n"
#define pll pair<ll, ll> 
#define vll vector<ll> 
#define rub cout << "------------------------------------\n"
//#define min(a, b, c) min(a, min(b, c))
//#define max(a, b, c) max(a, max(b, c))
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
string str;
ll n,m,a,b,temp;
vector<pair<char,char>> q;
bool f(int mid)
{
    int pos=mid;
    char c=str[mid];
    for(int i=0;i<q.size();i++)
    {
    if(q[i].fi!=c)
    continue;
    if(pos==0 && q[i].se=='L')
    return 1;
    if(q[i].se=='L')
    {c=str[pos-1];
    pos--;}
    else
    {
        if(pos!=n-1)
        {
        c=str[pos+1];
        pos++;
        }
    }
    }
    return 0;
}
bool fr(int mid)
{
    int pos=mid;
    char c=str[mid];
    for(int i=0;i<q.size();i++)
    {
    if(q[i].fi!=c)
    continue;
    if(pos==n-1 && q[i].se=='R')
    return 1;
    if(q[i].se=='L' && pos!=0)
    {c=str[pos-1];
    pos--;}
    else
    {
        c=str[pos+1];
        pos++;
    }
    }
    return 0;
}
//set<ll> s;
vll v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	cin>>m;
	cin>>str;
	while(m--)
	{
	    char a,b;
	    cin>>a>>b;
	    q.pb({a,b});
	}
	int l=0;
	int r=n-1;
	int mid;
	while(l<=r)
	{
	   mid=(l+r)/2;
	   if(f(mid))
	   l=mid+1;
	   else
	   r=mid-1;
	}
   if(!f(l))
   l--;
   //deb(l);
//	nl;
   vector<int> ans(n,0);
	for(int i=0;i<=l;i++)
	{
	    ans[i]=1;
	}
	l=0;
	r=n-1;
	while(l<=r)
	{
	    int mid=(l+r)/2;
	    if(fr(mid))
	    r=mid-1;
	    else
	    l=mid+1;
	}
	if(!fr(r))
	r++;
	for(int i=n-1;i>=r;i--)
	{
	    ans[i]=1;
	}
	cout<<count(0,ans);
}