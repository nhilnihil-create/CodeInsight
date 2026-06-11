#include <bits/stdc++.h>
using namespace std;
struct P
{
    int x, y,z;
    bool operator<(const P &a)const{
        if(y!=a.y) return y>a.y;
        return x>a.x;
    }
};
vector<int> v[211111];
//bitset<4001000> b;
int i,n,d,m,k,a,b,c;
int e;
int o[211111];
int l[211111];
int j[1];

int dx[10]={0,1,0,-1,1,1,-1,-1},dy[10]={1,0,-1,0,1,-1,1,-1},dz[10]={0,0,0,0,1,-1};
int px[10]={-1,1,1,-1,1,1,-1,-1},py[10]={1,1,-1,-1,1,-1,1,-1};
long long mod=1000000007,mod2=1000000009,mod3=2017;
long long x,z=1987654321987654321,y;
double pi=3.14159265;
P u[1];
stack<int> s;
//set<int> se[33],s1;

//priority_queue<P> q;
queue<int> q,q1;
string r[555],r5,r6;

char r1[11],r2[11];
//2147483647
//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<int,int> p;
//v.resize(unique(v.begin(),v.end())-v.begin());

bool as(P a,P b)
{
    //if(a.y!=b.y)
    //return a.y>b.y;
    return a.x>b.x;
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//rng();

void f(int n)
{
    for(int h=0;h<v[n].size();h++)
    if(o[v[n][h]]==-1)
    {
        o[v[n][h]]=o[n]+1;
        f(v[n][h]);
    }
}

int g(int n)
{
    if(l[n]>=0) return l[n];
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 0;
    l[n]=1-g(n-2);
    return l[n]=max(l[n],1-g(n-1));
}

int main()
{
    scanf("%d",&a);
    if(a==1)
    {
        puts("First");
        return 0;
    }
    for(int t=1;t<a;t++)
    {
        scanf("%d %d",&n,&m);
        v[n].push_back(m);
        v[m].push_back(n);
    }
    memset(o,-1,sizeof(o));
    o[1]=0;
    f(1);
    n=m=0;
    for(int t=2;t<=a;t++)
        if(o[t]>n)
        n=o[t],m=t;
    memset(o,-1,sizeof(o));
    o[m]=1;
    f(m);
    n=m=0;
    for(int t=1;t<=a;t++)
        if(o[t]>n)
        n=o[t],m=t;
    //printf("%d\n",n);
    memset(l,-1,sizeof(l));
    if(g(n)==0) puts("Second");
    else puts("First");
}
