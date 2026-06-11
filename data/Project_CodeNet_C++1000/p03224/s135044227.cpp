#include <bits/stdc++.h>
#define INT long long int
#define MOD 998244353
#define oo 6*(1e18)
using namespace std;
INT n, a[501] = {0, 0, 1}, e[100010];
vector<INT> G[501];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    if( n == 1 )
    {
        cout<<"Yes\n2\n1 1\n1 1\n";
        return 0;

    }
    for(int i = 3 ; i <= 500 ; i++ )
    {
        a[i] = a[i-1] + i-1;
        if( a[i] <= 100000 ) e[a[i]] = i;
    }
    if( !e[n] ) cout<<"No\n";
    else
    {
        cout<<"Yes\n"<<e[n]<<"\n";
        for(int i = 1, p = 1 ; i <= e[n]-1 ; i++ )
            for(int j = i+1 ; j <= e[n] ; j++ )
                G[i].push_back(p), G[j].push_back(p++);
        for(int i = 1 ; i <= e[n] ; i++ )
        {
            cout<<G[i].size()<<" ";
            for(INT x: G[i]) cout<<x<<" ";
            cout<<"\n";
        }
    }
}
