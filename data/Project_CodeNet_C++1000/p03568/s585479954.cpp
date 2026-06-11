#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int n; cin >> n;
    ll ans=1;
    ll odd=1;

    for(int i = 0; i < n; i++) {
        int a;cin >> a;
        if(a%2==0) odd *= 2;
        ans *= 3;
    }

    cout << ans - odd << endl;

    return 0;
}