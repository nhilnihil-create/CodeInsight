#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i=0;i<N;i++) cin >> a[i];
    for (int i=0;i<N;i++) cin >> b[i];
    ll cnta = 0;
    ll cntb = 0;
    for (int i=0;i<N;i++){
        if (a[i] > b[i]) cntb += a[i]-b[i];
        else if (a[i] < b[i]) cnta += (b[i]-a[i])/2;
    }
    if (cnta >= cntb) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}