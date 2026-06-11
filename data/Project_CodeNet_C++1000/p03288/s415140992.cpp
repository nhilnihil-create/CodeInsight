#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
#define int long long
signed main()
{
    int r;cin >> r;
    if(r < 1200)puts("ABC");
    else if(r < 2800)puts("ARC");
    else puts("AGC");
    return 0;
}