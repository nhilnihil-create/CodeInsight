#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <bits/stdc++.h>
#include <string.h>
#define inf 0x7fffffff
using namespace std;
struct P
{
    int x,y,z;

    bool operator<(const P &a)const{
       // if(y!=a.y)
       // return y>a.y;
       return x>a.x;
//        return z>a.z;
    }
};

vector<int> v;
int a,b,c,n,m,i,o[1<<26],k,d,e,dy[15]={0,0,-1,1,-1,1,-1,1},dx[15]={-1,1,0,0,1,1,-1,-1};
int l[201][115];
//long long x,y,z[10055];
P u[200];
int j[44];
//queue<int> q,q1;
//stack<int> s;
queue<int> q;
long long x,y=0,z[99];

//deque<int> d;
//'1'==49;
//'A'==65;
//'a'==97;
//unordered_map<int, int > p[100010];
set<int> s;
string r,r1;
//char r1[555],r2[555];

bool as(int a,int b)
{
     return a>b;

}

int f(int a)
{
    return a%10+a/10;
}

//2147483647
int main()
{
    cin>>r;
    for(int t=1;t<1<<26;t++) o[t]=987654321;
    for(int t=0;t<r.size();t++)
    {
        i^=(1<<(r[t]-'a'));
        for(int h='a';h<='z';h++)
        {
            o[i]=min(o[i],o[i^(1<<(h-1))]+1);
        }
    }
    if(i==0) puts("1");
    else printf("%d",o[i]);
}


