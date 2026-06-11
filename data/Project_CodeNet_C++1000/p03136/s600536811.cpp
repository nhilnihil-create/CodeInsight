#define George_Plover
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define EPS (1e-9)
#define MAXN 600001
#define MOD 998244353
#define ull unsigned long long
#define LL long long
using namespace std;
int n;
int L[20];
int main()
{
    
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>L[i];
    }
    sort(L+1,L+n+1);
    int sum=0;
    for(int i=1;i<n;i++)
        sum+=L[i];
    if(sum>L[n])
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}


