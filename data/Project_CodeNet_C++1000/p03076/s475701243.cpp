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
int arr[5],ans,cost[5];
void recur(int t,int used[])
{
    int f=0,rem=0;
    for(int i=0; i<5; i++)
    {
        if(!used[i])
        {
            f=1;
            rem=0;
            if(t%10){
               rem=10-(t%10);
            }

            used[i]=1;
            recur(t+arr[i]+rem,used);
            used[i]=0;

        }
    }
    if(!f)
        ans=min(ans,t);

}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);

    for(int i=0; i<5; i++)
        cin>>arr[i];
    int used[20]= {0};
    ans=INT_MAX;
    recur(0,used);
    cout<<ans<<endl;



    return 0;
}
