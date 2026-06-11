#include <bits/stdc++.h>
using namespace std;
int main() {
    int N=3;
    vector<int> c(4);
    int a,b;
    for (int i=0;i<N;i++) {
        cin >> a >> b;
        c[a-1]++;
        c[b-1]++;
    }
    string ans;
    for (int i=0;i<4;i++) {
        if (c[i]<1 || 2<c[i]) {
            ans = "NO";
            break;
        }
    }
    if (ans.empty()) ans = "YES";
    cout << ans << '\n';
    return 0;
}