#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int neighbour( string* a ,int i , int j , int h, int w)
{
    int ans =0;
    if( i-1>=0 && a[i-1][j] == '#')
            ans++;
    if( i+1<h && a[i+1][j] == '#')
        ans++;
    if( j-1>=0 && a[i][j-1] == '#')
        ans++;
    if( j+1<w && a[i][j+1] == '#')
        ans++;
    return ans;
}
int main()
{
    ll h ,w;
    cin>>h>>w;
    string* a = new string[h];
    for(int i=0;i<h;i++)
    {
        cin>>a[i];
    }
    bool ans = true;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if( a[i][j] =='#')
            {
                int n = neighbour( a,i,j,h,w);
                if( n==0 )
                    ans = false;
            }
        }
    }
    if( ans)
        cout<<"Yes";
    else
        cout<<"No";
}