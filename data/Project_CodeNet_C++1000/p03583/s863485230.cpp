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
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=1e6+10;
const int mod=1e9+7;

int main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=3500;i++)
    {
        for(ll j=1;j<=3500;j++)
        {
            ll a=i*j*n;
            ll b=4*i*j-n*(i+j);
            if(b>0&&(a%b==0))
            {
                cout<<i<<" "<<j<<" "<<a/b<<endl;
                return 0;
            }
        }
    }

}
