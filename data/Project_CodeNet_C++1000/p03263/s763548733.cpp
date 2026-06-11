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
int maps[520][520];
struct A
{
    int x1,y1,x2,y2;
    A(int x,int y,int xx,int yy):
        x1(x),y1(y),x2(xx),y2(yy) {}

};
int main()
{
    vector<A> a;
    int h,w;
    cin>>h>>w;
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
        {
            cin>>maps[i][j];
        }
    }
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w-1; j++)
        {
            if(maps[i][j]%2==1)
            {
                a.push_back(A(i,j,i,j+1));
                maps[i][j+1]++;

            }
        }
    }
    for(int i=1; i<=h-1; i++)
    {
        if(maps[i][w]%2==1)
        {
            a.push_back(A(i,w,i+1,w));
            maps[i+1][w]++;
        }
    }
    printf("%d\n",a.size());
    for(int i=0; i<a.size(); i++)
    {
        printf("%d %d %d %d\n",a[i].x1,a[i].y1,a[i].x2,a[i].y2);
    }

    return 0;
}
