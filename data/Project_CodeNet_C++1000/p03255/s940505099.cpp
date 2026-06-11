#include <bits/stdc++.h>
using namespace std;
//using lint = long long;

struct P
{
    long long x,y,z;

    bool operator<(const P &a)const{
              return x<a.x;
    }

};

vector<int> v[1];
//bitset<4001000> b;
int a,c,i,b,n,m,k,d;//dy[15]={0,1,0,-1,-1,1,-1,1},dx[15]={1,0,-1,0,1,1,-1,-1};//
long long o[522122];
long long l[552221];
int j[1];
int e;
int dx[10]={0,1,0,-1,1,1,-1,-1},dy[10]={1,0,-1,0,1,-1,1,-1},dz[10]={0,0,0,0,1,-1};
long long x,y,mod=1000000007,mod2=1000000009,mod3=2017;
long long z;
double pi=3.14159265;
P u[1];
//stack<int> s;

//set<long long> s;
queue<int> q,q1;

//2147483647
//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<int,int> p;
//list<int> l;

//string r,r1;
//char r[1333336];
//deque<int> de;
//srand((int)time(NULL));
bool as(P a,P b)
{
    if(a.x*b.y!=b.x*a.y)
    return a.x*b.y<b.x*a.y;
    return a.y>b.y;
}

long long f(int n,int m)
{
    return l[m]-l[n-1];

}

int main()
{
    x=mod*mod*4;
    scanf("%d %d",&a,&b);
    for(int t=1;t<=a;t++)
    {
        scanf("%lld",&o[t]);
        //o[t]+=o[t-1];
    }
    for(int t=1;t<=a;t++)
    {
        l[t]=o[a-t+1],l[t]+=l[t-1];
        //printf("%lld ",l[t]);
    }
    for(int t=1;t<=a;t++)
    {
        y=l[t]+(long long)t*b;
        long long i=2;
        for(int h=1;h<=a;i++,h+=t)
        {
            z=0;
            if(h+t-1<=a)
            {
                if(i>2)
                z+=(l[h+t-1]-l[h-1])*(i*i-(i-1)*(i-1));
                else

                z+=(l[h+t-1]-l[h-1])*(i*i);
            }
            else
            {
                if(i>2)
                z+=(l[a]-l[h-1])*(i*i-(i-1)*(i-1));
                else
                    z+=(l[a]-l[h-1])*(i*i);
            }
            z=min(z,mod*mod);
            y+=z;
            y=min(y,mod*mod);
        }
        //printf("##%lld\n",(long long)a*b+z);
        x=min(x,y);
    }
    printf("%lld",x+(long long)a*b);
}
//1 4 3 2 1
