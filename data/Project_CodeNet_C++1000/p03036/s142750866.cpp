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
	int r,d,x;cin>>r>>d>>x;
	vector<int> v(12);
	v[1]=x;
	for(int i=2;i<=11;i++){
		v[i]=r*v[i-1]-d;
		cout<<v[i]<<nl;
	}

}

