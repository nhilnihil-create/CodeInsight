#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin>>n;
    if(n%2==0)
    {
        cout<<n*(n-2)/2<<endl;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(n-i+1!=j)
                    cout<<i<<" "<<j<<endl;
    }
    else
    {
        cout<<(n-1)*(n-3)/2+(n-1)<<endl;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(n-i!=j)
                    cout<<i<<" "<<j<<endl;
    }

	return 0;
}
