#include <bits/stdc++.h>
using namespace std;
struct P
{
    //string r;
    int x,y,z;

    bool operator<(const P &a)const{
       // if(y!=a.y)
       // return y>a.y;
       return x>a.x;
//        return z>a.z;
    }
};

vector<int> v[100055],v1[100055];
//bitset<4001000> b;
int a,c,i,b,k,n,d,m,e;//dy[15]={0,1,0,-1,-1,1,-1,1},dx[15]={1,0,-1,0,1,1,-1,-1};//
int l[111010];
int o[300330];
int dx[10]={0,1,0,-1,1,1,-1,-1},dy[10]={1,0,-1,0,-1,1,-1,1},dz[10]={0,0,0,0,1,-1};

long long x,y,z,mod=1000000007;
P u[1130],u1[1111];
int j[222210];
stack<int> s;
queue<long long> q;
//priority_queue<P> q;
//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<long long,int > p;
//list<int> l;
string r;
//char r[310][333];
deque<int> de;

bool as(P a,P b)
{
   // if(a.x!=b.x)
        return a.x<b.x;
    //return a.y>b.y;
}

int f(int a)
{
    if((a%4==0&&a%100)||a%400==0) return 1;
    return 0;
}

int main()
{
    scanf("%d %d %d",&a,&b,&c);
    if((long long)b*c<a||b+c>a+1)
    {
        puts("-1");
        return 0;
    }
    for(int t=1;t<=a;o[t]=t,t++);
    d=a;
    for(;(long long)b*(c-1)>=d;c--,d--);
    for(int t=1;t<=d;t+=b)
    {
        for(int w=t,h=min(d,t-1+b);w<h;w++,h--)
        swap(o[w],o[h]);
    }
    for(int t=a;t>0;t--)
        printf("%d ",o[t]);
}
