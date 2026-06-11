#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    pair<int, int> itv[M];
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        itv[i].first = b;
        itv[i].second = a;
    }
    sort(itv, itv+M);
    int ans = 0;
    int t = 0;
    for(int i = 0; i < M; i++) {
        if(itv[i].second < t) {
            continue;
        }
        t = itv[i].first;
        ans++;
    }
    cout << ans << endl;
    return 0;
}