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
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll arr[200][15],money[200][15],ans,res[20],n;
void check(int used[])
{
    int cnt[n+5]= {0};
    for(int i=0; i<10; i++)
    {
        if(used[i])
        {
            for(int j=0; j<n; j++)
            {
                if(arr[j][i])
                    cnt[j]++;
            }
        }
    }
    ll sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=money[i][cnt[i]];
    }
    ans=max(ans,sum);
}
void recur(int pos,int used[])
{
    for(int i=pos; i<10; i++)
    {
        if(!used[i])
        {
            used[i]=1;
            check(used);
            recur(i+1,used);
            used[i]=0;
        }
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<10; j++)
            cin>>arr[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<=10; j++)
            cin>>money[i][j];
    ans=-INT_MAX;
    int used[15]= {0};
    recur(0,used);
    cout<<ans<<endl;


    return 0;
}
