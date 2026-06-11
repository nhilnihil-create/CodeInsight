#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int a[100000];
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> a[i];

    map<int, int> mp;
    for(int i=0; i<N; i++) mp[a[i]]++;

    int ans = 0;
    for(auto p: mp) {
        int x = p.first;
        int n= p.second;
        if(n < x) ans += n;
        else ans += n-x;
    }
    cout << ans << endl;
}