#include<bits/stdc++.h>

using namespace std;

int a[200006];

int main()
{
    int n,v;
    long long j=0;
    cin>>n;
    for(int i=0;i<n;i++)
        {
        cin>>v;
        a[i]=v;
        }
    if(a[0]!=0)
        {
        cout<<-1;
        return 0;
        }
    for(int i=1;i<n;i++)
        {
        //////
        if (a[i]-a[i-1]==1)
            {
			j++;
            }
		//////
		else if(a[i]-a[i-1]<1)
            {
			j=j+a[i];
            }
        //////
        else if(a[i]-a[i-1]>1)
            {
            cout<<-1;
            return 0;
            }
        }
    cout<<j;
}
