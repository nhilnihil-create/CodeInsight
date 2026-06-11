#include <bits/stdc++.h>
using namespace std;
//using lint = long long;

struct P
{
    int x, y;

    bool operator<(const P &a)const{
              return y>a.y;
    }

};


//vector<P> v[100100];
vector<long long> v;
vector<char> vs[1111];
//bitset<4001000> b;
int a,c,i,b,n,m,k,d;//dy[15]={0,1,0,-1,-1,1,-1,1},dx[15]={1,0,-1,0,1,1,-1,-1};//
int o[111111];
int l[111111];
//int z1[1000100],z2[1000100];
int j[1];
int e[1];

int dx[10]={0,1,0,-1,1,1,-1,-1},dy[10]={1,0,-1,0,1,-1,1,-1},dz[10]={0,0,0,0,1,-1};
long long x,y,mod=1000000007,mod2=1000000009,mod3=2017;
long long z;
double pi=3.14159265;
P u[1111];
//stack<int> s;

//set<long long> s;
queue<int> q;

//2147483647
//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<long long,int> p;
//list<int> l;

string r;
//char r[1100222],r1[1101000];
//deque<int> de;
//srand((int)time(NULL));


bool as(P a,P b)
{
    if(a.x!=b.x)
    return a.x<b.x;
    return a.y<b.y;
}


int main()
{
    scanf("%d",&a);
    for(int t=1;t<=a;t++)
        scanf("%d %d",&u[t].x,&u[t].y);
    d=((u[1].x+u[1].y)&1);
    for(int t=2;t<=a;t++)
        if(d!=((u[t].x+u[t].y)&1))
    {
        puts("-1");
        return 0;
    }
    if(!d)
    {
        v.push_back(1);
        for(int t=1;t<=a;t++)
            u[t].x++,vs[t].push_back('L');
    }
    long long k=1;
    for(int i=1;i<=33;k*=2,i++)
    {
        v.push_back(k);
        for(int j=1;j<=a;u[j].x/=2,u[j].y/=2,j++)
        if(u[j].x&1)
        {
            if(((u[j].x-1)&2)!=(u[j].y&2))
            {
                u[j].x--;
                vs[j].push_back('R');
            }
            else
            {
                u[j].x++;
                vs[j].push_back('L');
            }
        }
        else
        {
            if(((u[j].y-1)&2)!=(u[j].x&2))
            {
                u[j].y--;
                vs[j].push_back('U');
            }
            else
            {
                u[j].y++;
                vs[j].push_back('D');
            }
        }
    }
    v.push_back(k);
    for(int i=1;i<=a;i++)
    {
        if(u[i].x==-1) vs[i].push_back('L');
        if(u[i].x==1) vs[i].push_back('R');
        if(u[i].y==-1) vs[i].push_back('D');
        if(u[i].y==1) vs[i].push_back('U');
    }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)
        printf("%lld ",v[i]);
    puts("");
    for(int i=1;i<=a;i++)
    {
        for(int j=0;j<vs[i].size();j++)
            printf("%c",vs[i][j]);
        puts("");
    }
}
