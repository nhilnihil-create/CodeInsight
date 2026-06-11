#include<iostream>
#include<vector>
#include<math.h>
#include<string.h>
#include<algorithm>


using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(),x.end()
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define vi vector<int>
#define vstr vector<string>
#define vbool vector<bool>
#define vvi vector<vector<int> >
#define mii map<int,int>
#define pb push_back
#define pii pair<int,int>
#define vpair vector<pii > 
#define mkp make_pair
#define scan(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) {cout<<a[i]<<' ';}cout<<'\n'
#define mem(a,v) memset(a,v,sizeof(a))
#define loop(i,a,b) for (int i = a; i < b; i++)
#define loope(i,a,b) for (int i = a; i <= b; i++)
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PRECISION std::cout.unsetf ( std::ios::fixed );std::cout.precision(9)
#define PI 3.14159265
#define S second
#define F first
#define CHECK cout<<"CHEDEDWB"<<endl
#define br '\n'
int mod = 1e9+7;
int inf = 1e18;
int m_inf = INT_MIN;

void solve()
{
	vi arr(5);
	scan(arr,5);
	int k;
	cin>>k;
	bool ok = true;
	loop(i,0,4)
	{
		loop(j,i+1,5)
		{
			int d = abs(arr[j]-arr[i]);
			if(d>k)
			{
				cout<<":("<<endl;
				ok = false;
				break;
			}
		}
		if(!ok)
			break;
	}
	if(ok)
		cout<<"Yay!"<<endl;
}

int32_t main()
{
	FastIO; PRECISION;
	int t = 1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
} 