
// Problem : C - Go Home
// Contest : AtCoder Regular Contest 070
// URL : https://atcoder.jp/contests/arc070/tasks/arc070_a
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

//Dragon_warrior7(IITK)
#include <bits/stdc++.h>
#include<chrono>
using namespace std::chrono; 
using namespace std;
#define ll long long
#define pb push_back
#define nl cout << '\n'
#define sor(x) sort(x.begin(), x.end())
#define rev(v) reverse(v.begin(), v.end())
#define maxin(v) *max_element(v.begin(), v.end())
#define minin(v) *min_element(v.begin(), v.end())
#define sumall(vect) accumulate(vect.begin(), vect.end(), 0)
//#define count(x, vect) count(vect.begin(), vect.end(), x)
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
ll n,m,a,b,temp;
string str;
set<ll> s;
vll v;
ll x,y,c;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	auto start = high_resolution_clock::now(); 
	cin>>a>>b>>c;
	cin>>x>>y;
	ll mi=llmax;
	for(int i=0;i<=x;i++)
	{
		mi=min(mi,a*i+c*(2*(x-i))+b*max((ll)0,y-(x-i)));
	}
	for(int i=0;i<=y;i++)
	{
		mi=min(mi,b*i+c*2*(y-i)+a*max((ll)0,x-(y-i)));
	}
	cout<<mi;
	return 0;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
	cout<<"\nRun time = ";
	cout <<fixed<<setprecision(5)<<(long double)duration.count()/1000<<" ms";
}