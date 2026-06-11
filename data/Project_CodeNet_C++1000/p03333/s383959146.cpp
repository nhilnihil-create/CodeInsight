#include <bits/stdc++.h>
using namespace std;

struct P
{
    int x,y,z;
    bool operator<(const P &a)const{
              return x>a.x;
    }
};

vector<int> v[211];
//bitset<4001000> b;
int a,c,i,b,k,n,d,e,m;//dy[15]={0,1,0,-1,-1,1,-1,1},dx[15]={1,0,-1,0,1,1,-1,-1};//
long long o[111220];
long long l[113310];
int j[2112];
int dx[10]={1,0,-1,0,1,1,-1,-1},dy[10]={0,1,0,-1,1,-1,1,-1},dz[10]={0,0,0,0,1,-1};


long long x,y,mod=1000000007;
long long z;

P u[100550];
stack<int> s;

//set<int> s;
queue<int> q;


//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<int,int> p[11];
//list<int> l;

string r;
//char r[33];
//deque<int> de;
bool as(int a,int b)
{
    return b<a;
}

int main()
{
    scanf("%d",&a);
    for(int t=1;t<=a;t++)
        scanf("%lld %lld",&o[t],&l[t]);
    sort(o+1,o+a+1,as);
    sort(l+1,l+a+1);
    for(int t=2;t<=a;l[t]+=l[t-1],o[t]+=o[t-1],t++);
    for(int t=1;t<=a;t++)
        x=max(max(x,o[t]-l[t]),max(o[t]-l[t-1],o[t-1]-l[t]));
    printf("%lld",x*2);
}






