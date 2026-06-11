#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
int x,y;
int a[20010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	cin>>x>>y;
	for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1)
        cout<<abs(y-a[1]);
    else
        cout<<max(abs(y-a[n]),abs(a[n-1]-a[n]));

	return 0;
}
