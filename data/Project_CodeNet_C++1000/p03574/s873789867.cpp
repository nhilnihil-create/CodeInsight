#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,k,n,h,w;
    string s;
    cin>>h>>w;
    char a[h+2][w+2];
    memset(a,'.',sizeof(a));
    /*
    replace (.) with 0
    count adjacent, increase
    */
    for(i=1; i<=h; i++)
        for(j=1; j<=w; j++)
        {
            cin>>a[i][j];
         //   if(a[i][j]=='.')
           //     a[i][j]='0';
        }
    for(i=1; i<=h; i++)
    {
        for(j=1; j<=w; j++)
        {
            if(a[i][j]!='#')
            {
                ll cnt=0;
                char c;
                if(a[i-1][j+1]=='#')
                    cnt++;
                if(a[i-1][j]=='#')
                    cnt++;
                if(a[i-1][j-1]=='#')
                    cnt++;
                if(a[i][j+1]=='#')
                    cnt++;
                if(a[i][j-1]=='#')
                    cnt++;
                if(a[i+1][j+1]=='#')
                    cnt++;
                if(a[i+1][j]=='#')
                    cnt++;
                if(a[i+1][j-1]=='#')
                    cnt++;
                c='0'+cnt;
                a[i][j]=c;
        //        cout<<c<<" ";
            }
        }
      //  cout<<endl;
    }
    for(i=1; i<=h; i++)
    {
        for(j=1; j<=w; j++)
            cout<<a[i][j];

        cout<<endl;
    }






    return 0;
}



