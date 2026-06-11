#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define pb(x) push_back(x)
#define MP(x,y) make_pair(x,y)
using namespace std;
ll gcd(ll a,ll b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
int hashe[5];
void solve()
{
    int a,b;
    cin>>a>>b;
    hashe[a]++,hashe[b]++;

    cin>>a>>b;
    hashe[a]++,hashe[b]++;

    cin>>a>>b;
    hashe[a]++,hashe[b]++;

    sort(hashe,hashe+5);
    if(hashe[4]==2&&hashe[3]==2&&hashe[2]==1&&hashe[1]==1)
    {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
int main()
{
	int t=1;
	//cin>>t;
	while(t--)
		solve();
	return(0);
}
