#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
 
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
// typedef pair<int,int> pii;
// tree <pii,null_type,greater<pii>,rb_tree_tag,tree_order_statistics_node_update> tr;
// cin.tie(0);
// std::ios::sync_with_stdio(false);
typedef long long LL;
const int N = 200005;
const int M = 205;
// const int V = 207;
// const int E = 60007;
const int INF = 0x3f3f3f3f;
const double inf = 2e9;
const double Pi = acos(-1);
const int MOD = 1e9+7;
const double eps = 1e-8;
int n,m;
char s[N];
int vis[N];
int main()
{
    while (~scanf("%s",s))
    {
        memset(vis,0,sizeof vis);
        int l = strlen(s);
        for (int i=0;i<l;i++)
            vis[s[i]-'a']++;
        sort(vis,vis+3);
        int a = vis[0];
        int b = vis[1];
        int c = vis[2];
        if (b>a+1 || c>a+1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
/*

abac

aba

babacccabab

*/