#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    ll ans=0;
    for(int i = 0; i < n; i++) {
        int a;cin >> a;
        ans += a-1;
    }
    cout<<ans << endl;

    return 0;
}