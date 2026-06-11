#include <bits/stdc++.h>

using namespace std;

int a[510][510],c[250250][4];
int h,w;


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>h>>w;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w-1;j++)
        {
            if(a[i][j]%2==1)
            {
                c[ans][0]=i;
                c[ans][1]=j;
                c[ans][2]=i;
                c[ans][3]=j+1;
                ans++;
                a[i][j+1]++;
            }
        }
    }
    for(int i=0;i<h-1;i++)
    {
        if(a[i][w-1]%2==1)
        {
            c[ans][0]=i;
            c[ans][1]=w-1;
            c[ans][2]=i+1;
            c[ans][3]=w-1;
            ans++;
            a[i+1][w-1]++;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<ans;i++)
    {
        cout << c[i][0] + 1 << " " << c[i][1] + 1 << " " << c[i][2] + 1 << " " << c[i][3] + 1 << endl;
    }
    return 0;
}

/*
2 2
0 3
5 4
*/
