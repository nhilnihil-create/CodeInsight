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
int n,m,mem[3009][3009];
string s,t;

int dp(int i, int j)
{
    if(i==n || j== m) return 0;
    if(mem[i][j] != -1) return mem[i][j];

    if(s[i] == t[j]) return mem[i][j] = 1 + dp(i+1, j+1);
    int c1 = dp(i+1, j);
    int c2 = dp(i, j+1);
    return mem[i][j] = max(c1,c2);
}

void build(int i, int j)
{
    if(i==n || j== m) return ;

    if(s[i] == t[j])
    {
        cout<<s[i];
        build(i+1, j+1);
    }
    else
    {
        int c1 = dp(i+1, j);
        int c2 = dp(i, j+1);

        if(dp(i, j) == c1) build(i+1, j);
        else build(i, j+1);
    }
}

 int main()
{
//freopen("calc.in","r",stdin);
//freopen("calc.out","w",stdout);
//__builtin_popcount()
input
        cin>>s>>t;
        n = s.size();
        m = t.size();

        memset(mem,-1,sizeof mem);
        dp(0, 0);

        build(0, 0);





return 0;
}
