/*
ID: hafiz.i1
TASK: milk2
LANG: C++
*/
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;

ll n,cnt=0,d,b,c;

ll coun(ll x)
{d=0,b=0,c=0;
    while(x>0){
        if(x%10==7)d=1;
        else if(x%10==5)b=1;
        else if(x%10==3)c=1;
        x/=10;
    }
    return (d&&b&&c);
}

void dfs(ll a)
{
    if(a>n)return;
    else if(coun(a))cnt++;
    dfs(a*10+3);
    dfs(a*10+5);
    dfs(a*10+7);
}

int main()
{
//    freopen("milk2.in", "r", stdin);
//    freopen("milk2.out", "w", stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    cin>>n;dfs(0);
    cout<<cnt<<endl;
}
