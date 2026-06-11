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
string s[500];
int row[]= {1,0,-1,0,1,-1,1,-1};
int colm[]={0,1,0,-1,1,-1,-1,1};
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>s[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(s[i][j]=='.')
            {
                int cnt=0;
                for(int k=0; k<8; k++)
                {
                    int u=i+row[k];
                    int v=j+colm[k];
                    if(0<=u && u<n && 0<=v && v<m)
                    {
                        if(s[u][v]=='#')
                            cnt++;
                    }
                }
                s[i][j]=(cnt+48);
            }

        }
    }
    for(int i=0; i<n; i++)
        cout<<s[i]<<endl;
    return 0;
}
