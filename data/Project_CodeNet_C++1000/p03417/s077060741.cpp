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
int row[]= {1,0,-1,0,1,-1,1,-1};
int colm[]= {0,1,0,-1,1,-1,-1,1};
int mat[2000][2000];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll n,m;
    cin>>n>>m;
   /* for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            mat[i][j]=1;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<8; k++)
            {
                int u=i+row[k];
                int v=j+colm[k];
                if(0<=u && u<n && 0<=v && v<m)
                {
                    mat[i][j]^=1;
                }
            }
            mat[i][j]^=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
*/
    ll x=min(n,m);
    ll y=max(n,m);
    if(x==1 && y==1)
        cout<<"1"<<endl;
    else if(x==1)
    {
        cout<<max(0ll,y-2)<<endl;
    }
    else if(x==2){
        cout<<"0"<<endl;
    }
    else{
        cout<<(x-2)*(y-2)<<endl;
    }

    return 0;
}
