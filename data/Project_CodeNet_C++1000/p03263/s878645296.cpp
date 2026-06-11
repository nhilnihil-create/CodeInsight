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
struct tree
{
    int a,b,c,d;
    tree(int a,int b,int c,int d)
        :a(a), b(b), c(c), d(d) {}
};
int mat[501][501];
int row[]= {-1,0,1,0,1,-1,1,-1};
int colm[]= {0,1,0,-1,1,-1,-1,1};
int r,c;
vector<tree>ans;
void c1()
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(mat[i][j]%2==0)
                continue;
             if(j+1<c){
                mat[i][j]--;
                mat[i][j+1]++;
                ans.push_back({i,j,i,j+1});
             }
        }
    }
}
void c2()
{
    for(int i=0; i<r; i++)
    {
        if(mat[i][c-1]%2 && i+1<r){
            mat[i][c-1]--;
            mat[i+1][c-1]++;
            ans.push_back({i,c-1,i+1,c-1});
        }
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);

    cin>>r>>c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin>>mat[i][j];
    c1();
    c2();

    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        tree it=ans[i];
        cout<<it.a+1<<" "<<it.b+1<<" "<<it.c+1<<" "<<it.d+1<<endl;
    }

    return 0;
}
