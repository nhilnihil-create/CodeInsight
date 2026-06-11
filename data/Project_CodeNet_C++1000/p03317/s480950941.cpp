#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N, K;
    cin >> N >> K;
    ll ans = (N-1+K-2)/(K-1);
    cout << ans << endl;
}