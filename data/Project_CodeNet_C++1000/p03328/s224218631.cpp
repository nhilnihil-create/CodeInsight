#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod (ll)1000000007
#define fast std::ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define input int t;cin>>t;while(t--)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define f(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, a, b) for (int i = (a); i >= (b); i--)
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define all(x) x.begin(), x.end()
#define cins(s) string s; cin>>s;
#define cini(i) int i; cin>>i;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
int i,j,k;
int main()
{
	ll a,b;
	cin>>a>>b;
	ll arr[999+1]={0};
	ll sum=1;
	for(i=1; i<=999; i++)
	{
		arr[i]=arr[i-1]+sum;
		sum++;
	}
	for(i=1; i<999; i++)
	{
		if(arr[i]-a == arr[i+1]-b )
		{
			cout<<arr[i]-a;
			break;
		}
	}

}
