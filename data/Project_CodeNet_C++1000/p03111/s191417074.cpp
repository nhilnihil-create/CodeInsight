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
int mn,n;
int x[34],arr[34];
void recur(int pos,int cost,int cur,int used[])
{
    if(pos==3)
    {
        mn=min(mn,cost);
        return;
    }
    if(cur==0)
    {
        for(int i=0; i<n; i++)
        {
            if(!used[i])
            {
                used[i]=1;
                recur(pos,cost,arr[i],used);
                used[i]=0;
            }
        }
    }
    else
    {
        int need=x[pos]-cur;
        if(need>10)
        {
            for(int i=0; i<n; i++)
            {
                if(used[i]==0)
                {
                    used[i]=1;
                    recur(pos,cost+10,cur+arr[i],used);
                    used[i]=0;
                }
            }
        }
        recur(pos+1,cost+abs(need),0,used);
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);

    cin>>n;
    for(int i=0; i<3; i++)
        cin>>x[i];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int used[50]= {0};
    mn=INT_MAX;
    recur(0,0,0,used);
    cout<<mn<<endl;


    return 0;
}
