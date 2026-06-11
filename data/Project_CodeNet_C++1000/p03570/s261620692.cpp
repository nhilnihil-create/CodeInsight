#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <bitset>
#include <fstream>
using namespace std;

#define pi pair<int,int>
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define pl pair<long long,long long>
#define pb push_back
#define vi vector<int>
#define ll long long

const int MAXN=200005,mod=1e9+7;
int w[(1<<26)+5];
char t[MAXN];

int main ()
{
    int a,b,c,d,e,f,k,q,m,res;

    scanf("%s", t);
    m=1<<26;

    for (a=1; a<m; a++)
        w[a]=1000000;

    w[0]=0;
    b=0;
    res=0;

    for (a=0; t[a]; a++)
    {
        c=(1<<(t[a]-'a'));
        b^=c;
        d=w[b]+1;

        for (c=0; c<26; c++)
        {
            e=b^(1<<c);
            d=min(d,w[e]+1);
        }

        res=d;
        w[b]=min(w[b],res);
    }

    printf("%d", res);

    return 0;
}
