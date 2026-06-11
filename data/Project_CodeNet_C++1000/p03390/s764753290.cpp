#include <bits/stdc++.h>
using namespace std;


struct P
{
    //string r;
    int x;
    long long y,z;

   /* bool operator<(const P &a)const{
       // if(y!=a.y)
       // return y>a.y;
              return y>a.y;
    }*/
};


vector<int> v[111];
//bitset<4001000> b;
int a,c,i,b,k,n,d,m;//dy[15]={0,1,0,-1,-1,1,-1,1},dx[15]={1,0,-1,0,1,1,-1,-1};//
int l[12];

int o[5][111455];
int dx[10]={0,1,0,-1,1,1,-1,-1},dy[10]={1,0,-1,0,-1,1,-1,1},dz[10]={0,0,0,0,1,-1};

int e;

long long x,y,mod=1000000007;
long long z[11];
P j[400];
P u[10],u1[100];
//stack<int> s;
//queue<int> q;
set<int> s;
priority_queue<int,vector<int>,greater<int> > q;
//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<int,int> p;
//list<int> l;
string r1,r;
//char r[5][111][111];
//deque<int> de;

//20921
bool as(P a,P b)
{
    return a.x<b.x;
}

int main()
{
    scanf("%d",&a);
    for(int t=1;t<=a;t++)
    {
        long long x,y,z,n=1,m=1000000000;
        scanf("%lld %lld",&x,&y);
        if(x>y) swap(x,y);
        z=x*y;
        for(;n<m;)
        {
            long long u=(n+m)/2;
            if(u*u>=z) m=u;
            else n=u+1;
        }
        if(n*n==z)
        {
            if(n==x)
            {
                printf("%lld\n",2*n-2);
            }
            else
            {
                printf("%lld\n",2*n-3);
            }
        }
        else
        {
            if((n-1)*n<z) printf("%lld\n",2*n-3);
            else printf("%lld\n",2*n-4);
        }


    }
}
