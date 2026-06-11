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
const int N = 100000 + 9;
int n,mem[N][5],a[N],b[N],c[N];

int dp(int i,int  pr)
{
    if(i > n)return 0;
    if(mem[i][pr] != -1) return mem[i][pr];

    int c1 = 0, c2 = 0, c3 = 0;

    if(pr != 0) c1 = a[i] + dp(i+1, 0);
    if(pr != 1) c2 = b[i] + dp(i+1, 1);
    if(pr != 2) c3 = c[i] + dp(i+1, 2);

    return mem[i][pr] = max({c1,c2,c3});
}

 int main()
{
//freopen("calc.in","r",stdin);
//freopen("calc.out","w",stdout);
//__builtin_popcount()
input
        cin>>n;
        forr(i,1,n)cin>>a[i]>>b[i]>>c[i];

        memset(mem,-1,sizeof mem);

        cout<<dp(1,4)<<endl;





return 0;
}
