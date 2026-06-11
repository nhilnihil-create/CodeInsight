#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const int mo = 1e9 + 7;
typedef long long ll;
ll n,a,b,ans;
ll c[100000];void solve(){ans = max(abs(c[n - 1] - b), abs(c[n - 2] - c[n - 1]));;}
main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>a>>b;
    rep(i,n)cin>>c[i];
    if(n==1)cout<<abs(c[0]-b)<<endl;
    else if(abs(c[n-2]-c[n-1])>abs(c[n-1]-b))cout<<abs(c[n-2]-c[n-1]);
    else cout<<abs(c[n-1]-b)<<endl;
    return 0;
}