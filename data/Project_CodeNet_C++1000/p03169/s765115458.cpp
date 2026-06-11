#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);

const double PI  = acos(-1.0);
using namespace std;
//typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//char rv[4]={'D','R','L','U'};
const double EPS = 1e-9;
const int N = 300 + 9;
int n,m,a[4];
double mem[N][N][N];


double dp(int p1, int p2, int p3)
{
    if(p1 + p2 + p3 == 0)return 0;
    if(mem[p1][p2][p3] == mem[p1][p2][p3])return mem[p1][p2][p3];

    double f = 0;
    if(p1) f += 1.0 * p1/n * (1.0 + dp(p1-1, p2, p3));
    if(p2) f += 1.0 * p2/n * (1.0 + dp(p1+1, p2-1 ,p3));
    if(p3) f += 1.0 * p3/n * (1.0 + dp(p1, p2+1, p3-1));
    double ex = f + 1.0 * (n-p1-p2-p3) / n ;
    ex/= (1.0 - 1.0 * (n-p1-p2-p3) / n);
   // ex += 1.0 * (n-p1-p2-p3) / (n - 1);
  //  ex = (n - (n-p1-p2-p3)) * 1,0 / (n-p1-p2-p3) ;
    return mem[p1][p2][p3] = ex ;
}

 int main()
{
//freopen("calc.in","r",stdin);
//freopen("calc.out","w",stdout);
//__builtin_popcount()
input
        cin>>n;
        int x;
        forr(i,1,n)
        {
            cin>>x;
            a[x]++;
        }

        memset(mem,-1,sizeof mem);
        cout<<fixed<<setprecision(9)<<dp(a[1],a[2],a[3])<<endl;






return 0;
}
