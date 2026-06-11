#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , m;
    cin>>n>>m;
    int L = INT_MIN , M = INT_MAX;
    for(int i=0;i<m;i++)
    {
        int l , m;
        cin>>l>>m;
        L = max( L , l);
        M = min( m , M);
    }
    int ans =0;
    for(int i=1;i<=n;i++)
    {
        if( L<= i && M>= i)
            ans++;
    }
    cout<<ans;
}