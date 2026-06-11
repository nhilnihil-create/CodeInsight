#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
using namespace std;
const long long INF=(long long)0x3f3f3f3f3f3f3f3f;
const int MOD=(int)1e9+7;

int main()
{
    /*ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    //freopen("output.txt","w+",stdout);
    //freopen("input.txt","r+",stdin);
    vector<long long> sum(8);
    vector<vector<long long>> sign,ans(8);
    for(int i=-1;i<=1;i+=2)
        for(int j=-1;j<=1;j+=2)
            for(int k=-1;k<=1;k+=2)
                sign.push_back(vector<long long>{i,j,k});
    long long n,m,a,b,c,mx=0;
    cin>>n>>m;
    while(n--&&cin>>a>>b>>c)
        for(int i=0;i<8;i++)
            ans[i].push_back(sign[i][0]*a+sign[i][1]*b+sign[i][2]*c);
    for(int i=0;i<8;i++)
        sort(ans[i].rbegin(),ans[i].rend());
    for(int i=0;i<8;i++)
        for(int j=0;j<m;j++)
            sum[i]+=ans[i][j];
    for(int i=0;i<8;i++)
        mx=max(mx,sum[i]);
    cout<<mx;
    return 0;
}
