#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll>pa;

const int N=2e5+100;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

double pi=acos(-1);
int a[N];
int main()
{
    int n,z,w;
    cin>>n>>z>>w;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n>1)
    cout<<max(abs(a[n]-w),abs(a[n-1]-a[n]));
    else 
    cout<<abs(a[n]-w);
    return 0;
}

