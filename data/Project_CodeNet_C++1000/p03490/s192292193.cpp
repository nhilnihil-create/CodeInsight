#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define ll long long
#define mod 1000000007
#define C 0.5772156649
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define pil pair<int,ll>
#define pii pair<int,int>
#define ull unsigned long long
#define base 1000000000000000000
#define fio ios::sync_with_stdio(false);cin.tie(0)
#define y1 y2
using namespace std;

const double g=10.0,eps=1e-12;
const int N=8000+10,maxn=200000+10,inf=0x3f3f3f3f;

vector<int>v[2];
bool d[2][3*N];
int x1,y1,x,y;
bool solve()
{
    int f=0;
    memset(d,0,sizeof d);
    d[0][x+N]=1;
    for(int i=0;i<v[0].size();i++)
    {
        for(int j=0;j<2*N;j++)
        {
            d[f^1][j]=false;
            if((j>=v[0][i]&&d[f][j-v[0][i]])||d[f][j+v[0][i]])
            {
                d[f^1][j]=1;
            }
        }
        f^=1;
    }
    return d[f][x1+N];
}
bool solve1()
{
    int f=0;
    memset(d,0,sizeof d);
    d[0][y+N]=1;
    for(int i=0;i<v[1].size();i++)
    {
        for(int j=0;j<2*N;j++)
        {
            d[f^1][j]=false;
            if((j>=v[1][i]&&d[f][j-v[1][i]])||d[f][j+v[1][i]])
            {
                d[f^1][j]=1;
            }
        }
        f^=1;
    }
    return d[f][y1+N];
}
int main()
{
    fio;
    string s;
    cin>>s>>x1>>y1;
    int i=0;
    while(i<s.size()&&s[i]=='F')x++,i++;
    int te=0,f=0;
    for(;i<s.size();i++)
    {
        if(s[i]=='T')
        {
//            cout<<i<<" "<<te<<endl;
            if(te)v[f].pb(te);
            te=0;
            f^=1;
        }
        else if(s[i]=='F')te++;
    }
    if(te)v[f].pb(te);
//    for(int i=0;i<v[0].size();i++)cout<<v[0][i]<<endl;
//    cout<<endl;
//    for(int i=0;i<v[1].size();i++)cout<<v[1][i]<<endl;
    if(solve()&&solve1())cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
/********************
TTTTFTF
0 0
********************/
