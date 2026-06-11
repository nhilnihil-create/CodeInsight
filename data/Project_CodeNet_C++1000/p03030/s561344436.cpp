#include<bits/stdc++.h>
using namespace std;
typedef	 long long int lli;
typedef long long ll;
typedef long double ld;
const int mod=1e9+7;
const int MAX=200005;
#define ALL(x) x.begin(),x.end()
#define all(x,k) x.begin(),x.begin()+k


void solve();

string getString(char x) 
{ 
    // string class has a constructor 
    // that allows us to specify size of 
    // string as first parameter and character 
    // to be filled in given size as second 
    // parameter. 
    string s(1, x); 
  
    return s;    
} 
bool sz(ll a, ll b)
{
	return a>b;
}
int main()
{


		solve();
		
		
	
	
	

return 0;
}

void solve()
{
	
int t,n;
string s;
	cin>>n;
	pair<pair<string ,int>,int >m[n+1];

for(int i=1;i<n+1;i++)
{
	cin>>s>>t;
	m[i]={{s,-t},i};
	
}
sort(m+1,m+(n+1));
	
	for(int i=1;i<=n;i++)
	{
		cout<<m[i].second<<"\n";
	}
}

