#include <bits/stdc++.h>
using namespace std;
//using lint = long long;

struct P
{
    int x,y;

    bool operator<(const P &a)const{
        if(x!=a.x)
              return x>a.x;
        return y>a.y;
    }

};

vector<long long> v[11];

//bitset<4001000> b;
int i,n,d,m,k,a,b,c,h;

int o[200311];
int l[11];
int j[1];
int e;


//int dx[10]={2,2,-2,-2,1,1,-1,-1},dy[10]={1,-1,1,-1,2,-2,2,-2};

int dx[10]={0,1,0,-1,1,1,-1,-1},dy[10]={1,0,-1,0,1,-1,1,-1},dz[10]={0,0,0,0,1,-1};
long long mod=998244353,mod2=1000000009,mod3=2017;
long long x,z,y;
double pi=3.14159265;
P u[3];
stack<long long> s;
//set<int> s[222][22];
//priority_queue<P> q;
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

string r;
//char r[222253];
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
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}


int main()
{
    scanf("%d %d %d",&a,&b,&c);
    for(int t=1;t<=a;o[t]=t,t++);
    o[a+1]=0;
    o[1]=1;
    for(int t=1;t<=c;t++)
    {
        scanf("%d %d",&n,&m);
        o[n]=min(o[n],m-1);
    }
    for(int t=1;t<=a;t++)
    {
        if(o[t]>o[t+1])
        {
            printf("%d",t);
            return 0;
        }
        o[t+1]=min(o[t]+1,o[t+1]);
    }
}




