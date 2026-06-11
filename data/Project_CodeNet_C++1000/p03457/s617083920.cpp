#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll pt = 0 , px =0 , py =0;
    bool ans = true;
    cout<<boolalpha;
    for(int i=0;i<n;i++)
    {
        ll ct , cx , cy;
        cin>>ct>>cx>>cy;
        if( (ct-pt) < (abs(cx-px)+abs(py-cy))  )
        {
            ans = false;
        } else
        {
            if( (ct-pt)%2 != (abs(cx-px)+abs(py-cy))%2 )
                ans = false;
        }
                px = cx;
        py = cy;
        pt = ct;
    }
    if( ans)
        cout<<"Yes";
    else cout<<"No";
}