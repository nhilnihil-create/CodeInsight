#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using ll = long long;
using namespace std;

void solve() {
    string n; ll k;
    cin>>n>>k;
    int pos=0;
    while(n[pos]=='1')
    pos++;

    if(k<=pos) cout<<'1'<<'\n';
    else cout<<n[pos]<<'\n';
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