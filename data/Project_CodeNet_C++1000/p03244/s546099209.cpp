#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;

const int mod = 1e9+7;
const int INF = 2000000;

int main() {
    int n;
    cin >> n;
    vector<int> C1(100010,0),C2(100010,0);
    int v[n];
    rep(i,n) cin >> v[i];
    for(int i=0;i<n;++i) {
        if(i & 1) ++C2[v[i]];
        else ++C1[v[i]];
    }
    int ind1 = max_element(C1.begin(), C1.end())-C1.begin();
    int ind2 = max_element(C2.begin(), C2.end())-C2.begin();
    int mval1 = C1[ind1], mval2 = C2[ind2];
    C1[ind1] = 0;
    C2[ind2] = 0;
    int sec1 = *max_element(C1.begin(), C1.end());
    int sec2 = *max_element(C2.begin(), C2.end());
    int ans;
    if(ind1 == ind2) ans = min(n-mval1-sec2, n-mval2-sec1);
    else ans = n - mval1 - mval2;
    cout << ans << endl;
}
