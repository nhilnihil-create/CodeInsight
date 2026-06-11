#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int MOD=1000000007;
const int nmax=2512;

int n,a,b;

int main()
{
    scanf("%d %d %d",&n,&a,&b);
    printf("%d %d",min(a,b),max(0,a+b-n));
    return 0;
}
