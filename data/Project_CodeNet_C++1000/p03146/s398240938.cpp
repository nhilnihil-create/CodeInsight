#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using ll = long long;
using namespace std;
int x, y, z, l, m, n, r, q, k, s;

void solve() {
    vector<int> c(10000,0);
    int count = 1;
    cin>>s;
    c[s]++;
    auto f = [&](int x){
        return x&1?3*x+1:x/2;
    };
    while(c[f(s)]<1){
        s = f(s);
        c[s]++;
        count++;
    }
    cout<<count+1<<'\n';


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