#include <bits/stdc++.h>
#define ll long long

using namespace std;

int m,k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>m>>k;
	int maxi=(1<<m)-1;
	if(k>maxi)
    {
        cout<<-1;
        return 0;
    }
    if(m==1)
    {
        if(k==1)
            cout<<-1;
        else
            cout<<"0 0 1 1";
        return 0;
    }

    for(int i=0;i<=maxi;i++)
        if(i!=k)
            cout<<i<<" ";

    cout<<k<<" ";

    for(int i=maxi;i>=0;i--)
        if(i!=k)
            cout<<i<<" ";

    cout<<k;

	return 0;
}
