//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,h,w,j,k;
    cin>>h>>w;
    char a[h][w];
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {
            cin>>a[i][j];
        }
    }
    bool ok=1;
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {
            bool black=0;
            if(a[i][j]=='#')
            {
                if(i!=0&&a[i-1][j]=='#')
                    black=1;
                if(i!=h-1&&a[i+1][j]=='#')
                    black=1;
                if(j!=0&&a[i][j-1]=='#')
                    black=1;
                if(j!=w-1&&a[i][j+1]=='#')
                    black=1;
            if(!black){
              ok=0;break;
            }
            }
        }

    }
    if(ok)
    cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';

    return 0;
}



