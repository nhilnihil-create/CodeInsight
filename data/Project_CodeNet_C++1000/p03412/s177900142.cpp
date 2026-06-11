#include <bits/stdc++.h>
#define INT long long
using namespace std;
INT n, a[200020], b[200020], c[200020], ans;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 0 ; i < n ; i++ ) cin>>a[i];
    for(int i = 0 ; i < n ; i++ ) cin>>b[i];
    for(int p = 0 ; p < 29 ; p++ )
    {
        INT T = (1<<p), flag = 0;
        for(int i = 0 ; i < n ; i++ ) c[i] = b[i]%(2*T);
        sort(c, c+n);
        for(int i = 0 ; i < n ; i++ )
        {
            flag += (int)(lower_bound(c, c+n, 2*T-(a[i]%(2*T))) - lower_bound(c, c+n, T-(a[i]%(2*T)))) - 1;
            flag += (int)(lower_bound(c, c+n, 4*T-(a[i]%(2*T))) - lower_bound(c, c+n, 3*T-(a[i]%(2*T)))) - 1;
        }
        if( flag%2 ) ans |= (1<<p);
    }
    cout<<ans<<endl;
    return 0;
}
