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
vector<int>v[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=1; i<=n; i++)
        sort(all(v[i]));
    int mn=INT_MAX,ans=0;
    for(int i=1; i<=n; i++)
    {
        if(mn==i){
            ans++;
            mn=INT_MAX;
        }
        if(v[i].size())
        {
            mn=min(mn,v[i][0]);
        }
    }
    if(mn!=INT_MAX)
        ans++;
    cout<<ans<<endl;


    return 0;
}
