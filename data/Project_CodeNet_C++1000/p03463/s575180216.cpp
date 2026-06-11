#include <bits/stdc++.h>
#define N 100005
typedef long long ll; 
using namespace std;
int main()
{
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    if((a-b)&1)puts("Borys");
    else puts("Alice");
    return 0;
}