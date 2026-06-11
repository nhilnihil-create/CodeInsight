#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using ll = long long;
using namespace std;
int x, y, z, l, m, n, r, q, k;

void solve() {
    int mdiff = INT_MAX;
    string s;
    cin>>s; n = s.size();
    for(int i=0;i<n-2;i++){
        int diff = abs(stoi(s.substr(i, 3))-753);
        mdiff = min(mdiff, diff);
    }
    cout<<mdiff<<'\n';

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