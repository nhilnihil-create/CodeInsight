#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,x) for(i=1;i<=x;i++)
#define sp(a) fixed<<setprecision(a)
using namespace std;
using ll = long long int;
using lo = unsigned long long int;
typedef vector<ll> vi;
typedef vector<lo> vl;
typedef vector<ll> vi;
typedef pair<ll,ll> par;
ll n,sm = 0,k;
int main()
{
	cin>>n;
	while(n--){
		cin>>k,sm+=(k-1);
	}
	cout<<sm<<'\n';
	return 0;
}