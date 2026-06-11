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
int arr[20];
int mat[20][20];
int n,m;
ll ans;
void recur(int pos,int used[])
{

    int cnt=0;
    for(int i=1; i<=m; i++)
    {
        int sum=0;
        for(int j=1; j<=n; j++)
        {
            if(mat[i][j] && used[j])
                sum++;
        }
        sum%=2;
        if(sum!=arr[i])
            break;
        cnt++;
    }
    if(cnt==m)
    {
        ans++;
    }

    for(int i=pos; i<=n; i++)
    {
        if(!used[i])
        {
            used[i]=1;
            recur(i+1,used);
            used[i]=0;
        }
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int k;
        cin>>k;
        for(int j=1; j<=k; j++)
        {
            int a;
            cin>>a;
            mat[i][a]=1;
        }
    }
    for(int i=1; i<=m; i++)
        cin>>arr[i];
    int used[20]= {0};
    recur(1,used);
    cout<<ans<<endl;


    return 0;
}
