#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e5+5;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int s[MAX],c[MAX],t[MAX],temp[MAX],res[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>s[i]>>t[i]>>c[i];
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<MAX; j++)
            temp[j]=0;
        for(int j=0; j<n; j++)
        {
            if(c[j]==i)
            {
                temp[s[j]-1]++;
                temp[t[j]]--;
            }
        }
        for(int j=1;j<MAX;j++)
          temp[j]+=temp[j-1];
        for(int j=0;j<MAX;j++)
          if(temp[j]) res[j]++;
    }
    int ans=0;
    for(int j=0;j<MAX;j++) ans=max(ans,res[j]);
    cout<<ans<<endl;
    return 0;
}
