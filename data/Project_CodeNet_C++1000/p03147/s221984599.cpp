#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool condition( int *a , int n)
{
    for(int i=0;i<n;i++)
    {
        if( a[i] >0)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    ll ans =0;
    while( !condition( h,n)  )
    {
        int l =0 ,r =0 ;
        bool ltaken = false;
        int lowest=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if( !ltaken  && h[i] >0 )
            {
                l = i;
                ltaken = true;
            }
            if( ltaken && (h[i] ==0 ) )
            {
                r  = i-1;
                for( int i= l ;i<=r;i++)
                {
                    lowest = min( lowest ,h[i]);
                }
                ans+= lowest;
                for(int i=l;i<=r;i++)
                {
                    h[i] -= lowest;
                }
                ltaken= false;
            }
            if( ltaken && i== n-1)
            {
                r = n-1;
                for( int i= l ;i<=r;i++)
                {
                    lowest = min( lowest ,h[i]);
                }
                ans+= lowest;
                for(int i=l;i<=r;i++)
                {
                    h[i] -= lowest;
                }
                ltaken= false;
            }
        }
    }
    cout<<ans;
}