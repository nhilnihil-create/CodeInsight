#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using ll = long long;
using namespace std;

void solve() {
    int n;
    cin>>n; int od=0;
    for (int j=1;j<=n;j=j+2) {
        int count =0;
        for (int i=1;i*i<=j;i++) {
            if (j%i==0) count++;
        }
        if(count == 4) od++;
    }
    cout<<od<<'\n';


}

int main()
{
    std::ios::sync_with_stdio(false); \
        std::cin.tie(NULL);
    int test;
    test=1;
    while (test--) {
        solve();
    }
    return 0;
}