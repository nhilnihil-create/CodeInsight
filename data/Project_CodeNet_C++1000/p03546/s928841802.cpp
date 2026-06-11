#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int c[10][10];
int s[10]={INF,INF,INF,INF,INF,INF,INF,INF,INF,INF};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h,w;cin>>w>>h;

    for(int i=0;i<10;i++)for(int j=0;j<10;j++)cin>>c[i][j];

    vector<int> v={0,1,2,3,4,5,6,7,8,9};

    do
    {
        int sum=0;
        for(int i=0;i<10;i++)
        {
            if(v[i]==1)break;
            sum+=c[v[i]][v[i+1]];
        }
        s[v[0]]=min(s[v[0]],sum);
    } while (next_permutation(v.begin(),v.end()));

    int ans=0;

    for(int i=0;i<w*h;i++)
    {
        int ia;cin>>ia;
        if(ia==-1)continue;
        ans+=s[ia];
    }

    cout<<ans<<"\n";

    return 0;
}
