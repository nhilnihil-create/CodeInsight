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
const int N = 3000 + 9;
int n,m;
double a[N],mem[N][N];


double dp(int i, int h)
{
    if(i > n)
    {
        if( h > n-h) return 1;
        return 0;
    }
    if(mem[i][h] == mem[i][h])return mem[i][h];

    double c1 = a[i] * dp(i+1, h+1);
    double c2 = (1.0-a[i]) * dp(i+1, h);

    return mem[i][h] = c1 + c2 ;
}

 int main()
{
//freopen("calc.in","r",stdin);
//freopen("calc.out","w",stdout);
//__builtin_popcount()
input
        cin>>n;
        forr(i,1,n)cin>>a[i];

        memset(mem,-1,sizeof mem);
        cout<<fixed<<setprecision(9)<<dp(1,0)<<endl;






return 0;
}
