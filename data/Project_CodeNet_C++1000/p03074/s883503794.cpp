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
const int N=2e5+10;
const int mod=1e9+7;
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    vector<int >v;
    cin>>s;
    int la=0;
    s+='*';
    if(s[0]=='0')
    {
        v.push_back(0);
    }
    for(int i=1; i<=n; i++)
    {
        if(s[i]!=s[i-1])
        {
            v.push_back(i-la);
            la=i;
        }
    }
    if(s[n-1]=='0')
    {
        v.push_back(0);
    }
    int sum=0,ma;
    if(2*k+1>=v.size())
    {
        cout<<n<<endl;
        return 0;
    }
    for(int i=0; i<2*k+1; i++)
    {
        sum+=v[i];
    }
    ma=sum;
    for(int i=2*k+1; i<v.size(); i+=2)
    {
        sum-=v[i-2*k-1];
        sum-=v[i-2*k];
        sum+=v[i];
        sum+=v[i+1];
        ma=max(ma,sum);
    }
    cout<<ma<<endl;
    return 0;
}
