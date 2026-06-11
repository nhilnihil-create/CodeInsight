#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using ll = long long;
using namespace std;
int x, y, z, l, m=0, n, r, q, k;

void solve() {
    int sum = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        sum+=num;
        m = max(m, num);
    }
    if(sum-m>m) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';

}

int main() 
{
    std::ios::sync_with_stdio(false); \
        std::cin.tie(NULL);
    int test;
    test  = 1;
    while (test--) {
        solve();
    }
    return 0;
}