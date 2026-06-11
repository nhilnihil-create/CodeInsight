#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int>graph[1000005];
bool vis[1000005];
int connection[1000005];
bool BPM(int node)
{
    int sz=graph[node].size();
    for(int i=0; i<sz; i++)
    {
        int child=graph[node][i];
        if(vis[child]==0)
        {
            vis[child]=1;
            if(connection[child]<0 || BPM(connection[child]))
            {
                connection[child]=node;
                return true;
            }
        }
    }
    return false;
}
int maxBPM(int n)
{
    memset(connection,-1,sizeof(connection));
    int res=0;
    for(int i=0; i<n; i++)
    {

        memset(vis,0,sizeof(vis));
        if(BPM(i))
            res++;

    }
    return res;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<pair<int,int> >R,B;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        R.push_back({x,y});
    }
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        B.push_back({x,y});
    }
  /*  sort(R.begin(),R.end(),cmp);
    sort(B.begin(),B.end(),cmp);
    for(auto x:R)
        cout<<x.first<<"      "<<x.second<<endl;
    bug
    bug
    for(auto x:B)
        cout<<x.first<<"      "<<x.second<<endl;
    int cnt=0;*/
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(R[i].first<B[j].first && R[i].second<B[j].second)
            {

               graph[i].push_back(j);

            }
        }
    }
    cout<<maxBPM(n)<<endl;
    return 0;
}
