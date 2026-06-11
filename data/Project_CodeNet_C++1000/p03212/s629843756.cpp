#include<bits/stdc++.h>
using namespace std;
#define in(a, n) for(int i=0;i<n;i++)
#define oo 1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void flush(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
//28 problems
//2*(900,1000,1100)
//6*30=180
//98:74:da:c0:ca:49
int a[100009];
ll n;
int q=0;
void solve(ll c,bool n7,bool n3,bool n5)
{
    if(c>n)
        return;
    if(n7&&n3&&n5)
        q++;
    solve(c*10+3,n7,1,n5);
    solve(c*10+7,1,n3,n5);
    solve(c*10+5,n7,n3,1);
}
int main()
{

    flush();
    cin>>n;
    solve(0,0,0,0);
    cout<<q;
}

