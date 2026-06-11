#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> l(90);
    l[0]=2;
    l[1]=1;
    for (int i=2; i<=86; ++i) {
        l[i]=l[i-1]+l[i-2];
    }

    int n;
    cin >> n;
    cout << l[n];

    return 0;
}
