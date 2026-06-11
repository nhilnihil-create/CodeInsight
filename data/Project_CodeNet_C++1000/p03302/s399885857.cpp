#include <bits/stdc++.h>
using namespace std;

struct P
{
    int x,y;

    bool operator<(const P &a)const{
              return x>a.x;
    }

};

vector<P> v[101103];
//bitset<4001000> b;
int a,c,i,b,k,n,d,m;//dy[15]={0,1,0,-1,-1,1,-1,1},dx[15]={1,0,-1,0,1,1,-1,-1};//
int o[100130];
int l[101103];
double j[1030];
int e[110];
int dx[10]={1,0,-1,0,1,1,-1,-1},dy[10]={0,1,0,-1,1,-1,1,-1},dz[10]={0,0,0,0,1,-1};
long long x,y,mod=998244353;
long long z;
double pi=3.14159265;
P u[10600];
stack<int> s;

//set<int> s;
queue<int> q;

//2147483647
//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<int,int> p,p1;
//list<int> l;

string r;
//char r[133];
//deque<int> de;
bool as(P a,P b)
{
    if(o[a.x]!=o[b.x])
    return o[a.x]<o[b.x];
    return a.y<b.y;
}


int main()
{
    scanf("%d %d",&a,&b);
    if(a+b==15) puts("+");
    else if(a*b==15) puts("*");
    else puts("x");
}
