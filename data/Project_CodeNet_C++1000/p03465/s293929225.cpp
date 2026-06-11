#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define sep(i,b,a) for(ll i=b-1;i>=a;i--)
#define int long int
#define hell (int)(1e9+7)

using namespace std;

void solve()
{
    bitset <4000005> b(0);
    b[0]=1;
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
        b|=b<<x;
    }
    for(int i=0;i<=sum;i++){
        if(b[i]&&i>=(sum+1)/2){
            cout<<i;
            break;
        }
    }
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	//cin>>t;
	t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
xzu
dfw
eor
nat
jye

*/
