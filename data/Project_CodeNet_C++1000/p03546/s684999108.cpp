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
ll mat[500][500],digits[500][500];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            cin>>digits[i][j];
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];
    int t=50;
    while(t--)
    {
        for(int k=0; k<10; k++)
        {
            for(int i=0; i<10; i++)
            {
                for(int j=0; j<10; j++)
                {
                    digits[i][j]=min(digits[i][j],digits[i][k]+digits[k][j]);
                }
            }
        }
    }
    ll sum=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(mat[i][j]!=1 && mat[i][j]!=-1)
            {
                int cur=mat[i][j];
                sum+=digits[cur][1];
            }
        }
    cout<<sum<<endl;
    return 0;
}
