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
int n,mem[N],a[N];

int dp(int i=1)
{
    if(i == n)return 0;
    if(i > n) return 1e9+9;
    if(mem[i] != -1) return mem[i];

    int c1 = abs(a[i] - a[i+1]) + dp(i+1);
    int c2 = abs(a[i] - a[i+2]) + dp(i+2);
    return mem[i] = min(c1,c2);
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
        cout<<dp()<<endl;





return 0;
}
