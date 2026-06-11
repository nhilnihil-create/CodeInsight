#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
int t[5000];
int A,B,C,n;
int ans=inf;
void bfs(int l,int a,int b,int c,int mp)
{
    if(l==n)
    {
        if(a==A||b==B||c==C)
        {
            return ;
        }
        else
        {
            ans=min(ans,abs(a)+abs(b)+abs(c)+mp);
            return ;
        }
    }
    bfs(l+1,a-t[l],b,c,mp+(a==A?0:10));
    bfs(l+1,a,b-t[l],c,mp+(b==B?0:10));
    bfs(l+1,a,b,c-t[l],mp+(c==C?0:10));
    bfs(l+1,a,b,c,mp);
}

int main()
{
    cin>>n>>A>>B>>C;
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
    }
    bfs(0,A,B,C,0);
    cout<<ans<<endl;
    return 0;
}
