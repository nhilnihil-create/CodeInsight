#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<set>
using namespace std;
const int maxn=1e5+5;
const int N=55;
typedef unsigned long long ull;
typedef long long ll;
int w[N];
int p[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>w[i];
    int r=min(n,m),o,t;
    for(int i=0; i<=r; i++)
    {
        for(int j=0; j<=r-i; j++)
        {
            for(o=0; o<i; o++)
                p[o]=w[o];
            for(t=0; t<j; t++)
                p[o+t]=w[n-t-1];
            sort(p,p+i+j);
            int k=0,sum=0;
            while(k+i+j<m&&p[k]<0)
                k++;
            while(k<i+j)
                sum+=p[k],k++;;
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
}
