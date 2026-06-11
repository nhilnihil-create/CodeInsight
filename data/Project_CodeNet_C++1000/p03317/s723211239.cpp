//#define _GLIBCXX_DEBUG
//#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    int a[n]; for (int i = 0; i<n; i++) cin >> a[i];
    cout << (((n-k)+(k-2))/(k-1))+1 << "\n";
}