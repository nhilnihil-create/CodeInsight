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
const int N = 1000 + 9;
int n,m,mem[N][N], mod =1e9+7;
char a[N][N];


int dp(int i, int j)
{
    if(i == n && j==m)return 1;
    if(mem[i][j] != -1)return mem[i][j];
    int c1=0,c2=0;
    if(i+1<=n && a[i+1][j] =='.')c1 = dp(i+1, j);
    if(j+1<=m && a[i][j+1] =='.')c2 = dp(i, j+1);
    return mem[i][j] = (c1 + c2) % mod;
}

 int main()
{
//freopen("calc.in","r",stdin);
//freopen("calc.out","w",stdout);
//__builtin_popcount()
input
        cin>>n>>m;
        forr(i,1,n)forr(j,1,m)cin>>a[i][j];
        memset(mem, -1,sizeof mem);
        cout<<dp(1, 1)<<endl;






return 0;
}
