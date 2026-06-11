#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
int a[60];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++)
        cin>>a[i];
    int maxi=a[1];
    int mini=a[1];
    int maxind=1,minind=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>maxi)
            maxind=i,maxi=a[i];
        if(a[i]<mini)
            minind=i,mini=a[i];
    }

    if(maxi>=0 && mini>=0)
    {
        cout<<n-1<<endl;
        for(int i=1;i<n;i++)
            cout<<i<<" "<<i+1<<endl;
        return 0;
    }

    if(maxi<=0 && mini<=0)
    {
        cout<<n-1<<endl;
        for(int i=n;i>1;i--)
            cout<<i<<" "<<i-1<<endl;
        return 0;
    }

    if(maxi+mini>=0)
    {
        cout<<2*n-2<<endl;
        for(int i=1;i<=n;i++)
            if(i!=maxind)
                cout<<maxind<<" "<<i<<endl;

        for(int i=1;i<n;i++)
            cout<<i<<" "<<i+1<<endl;
        return 0;
    }

    cout<<2*n-2<<endl;
    for(int i=1;i<=n;i++)
        if(i!=minind)
            cout<<minind<<" "<<i<<endl;

    for(int i=n;i>1;i--)
            cout<<i<<" "<<i-1<<endl;


	return 0;
}
