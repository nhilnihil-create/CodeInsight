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
ll arr[5],n;
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        if(s[0]=='M')
            arr[0]++;
        else if(s[0]=='A')
            arr[1]++;
        else if(s[0]=='R')
            arr[2]++;
        else if(s[0]=='C')
            arr[3]++;
        else if(s[0]=='H')
            arr[4]++;
    }
    ll ans=0;
    for(int i=0; i<5; i++)
    {
        for(int j=i+1; j<5; j++)
        {
            for(int k=j+1; k<5; k++)
            {
            ans+=arr[i]*arr[j]*arr[k];
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
