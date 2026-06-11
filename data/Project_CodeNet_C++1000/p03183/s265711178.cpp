#include <bits/stdc++.h>
using namespace std;
//using lint = long long;

struct P
{
    int x,y,z;

    bool operator<(const P &a)const{
        if(x!=a.x)
              return x>a.x;
        return y>a.y;
    }

};

vector<int> v;

//bitset<4001000> b;
int i,n,d,m,k,a,b,c;

long long o[1333][11111];
int l[1];
int j[1];
int e;


//int dx[10]={2,2,-2,-2,1,1,-1,-1},dy[10]={1,-1,1,-1,2,-2,2,-2};

int dx[10]={0,1,0,-1,1,1,-1,-1},dy[10]={1,0,-1,0,1,-1,1,-1},dz[10]={0,0,0,0,1,-1};
long long mod=1000000007,mod2=1000000009,mod3=2017;
long long x,z,y;
double pi=3.14159265;
P u[3331];
stack<int> s;
//set<int> se;
//priority_queue<int,vector<int>,greater<int> > q;
//queue<int> q;
//2147483647
//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<int,int> p;
/*
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<long long, int, custom_hash> safe_map;
*/
//list<int> l;

//string r,r1;
char r[552];
//deque<int> de;
//srand((int)time(NULL));
/*bool as(P a,P b)
{
    if(a.x!=b.x)
    return a.x<b.x;
    return a.y<b.y;
}*/



bool as(P a,P b)
{
    //if(a.x!=b.x)
    //   return a.x<b.x;
    return a.x+a.y>b.x+b.y;


}

long long f(int n,int m)
{
    if(m<0) return -987654321987654321;
    if(n>a) return 0;
    if(o[n][m]>=0) return o[n][m];
    return o[n][m]=max(f(n+1,min(m-u[n].x,u[n].y))+u[n].z,f(n+1,m));
}

int main()
{
    memset(o,-1,sizeof(o));
    scanf("%d",&a);
    for(int t=1;t<=a;t++)
        scanf("%d %d %d",&u[t].x,&u[t].y,&u[t].z);
    sort(u+1,u+a+1,as);
    for(int t=1;t<=a;t++)
        x=max(x,f(t+1,u[t].y)+u[t].z);
    printf("%lld",x);
}



