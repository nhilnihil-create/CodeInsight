#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

#define mem(ar,a)       memset(ar,a,sizeof ar)
#define iOS           	ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pb(x)           push_back(x)
#define all(c)          c.begin(), c.end()
#define int             long long
#define ff              first
#define ss              second
#define nl              '\n'

int32_t main()
{
	iOS
	int a,b; cin>>a>>b;
	if(a>=13)
		cout<<b;
	else if(a<=5)
		cout<<0;
	else
		cout<<b/2;
}

