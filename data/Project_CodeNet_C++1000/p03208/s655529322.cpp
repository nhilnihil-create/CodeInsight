#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using ll = long long;
using namespace std;
int x, y, z, l, m, n, r, q, k;
//0 1 2 3 4 5 6 n = 7;
void solve() {
    cin>>n>>k;
    int a[100000];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int md = INT_MAX;
    sort(a, a+n);
    for(int i=0;i<=n-k;i++){
        md = min(md, a[i+k-1]-a[i]);
    }
    cout<<md<<'\n';
}

int main() 
{
    std::ios::sync_with_stdio(false); \
        std::cin.tie(NULL);
    int test;
    test = 1;
    while (test--) {
        solve();
    }
    return 0;
}