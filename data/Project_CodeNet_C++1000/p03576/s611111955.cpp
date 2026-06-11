#include <bits/stdc++.h>
using namespace std;

bool first(pair<long int, long int> a, pair<long int, long int> b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}
int main(){
    int N, K;
    cin >> N >> K;
    vector<pair<long int, long int>> point(N);
    for (int i = 0; i < N; i++) {
        long int x, y;
        cin >> x >> y;
        point[i] = {x, y};
    }
    sort(point.begin(), point.end(), first);
    
    long int ans;
    for (int i = 0; i < N-K+1; i++) {
        long int l = point[i].first;
        long int r;
        vector<long int> y;
        for (int j = i; j < N; j++) {
            y.insert(lower_bound(y.begin(), y.end(), point[j].second), point[j].second);
            if (j-i+1 >= K) {
                r = point[j].first;
                long int u, d;
                for (int k = 0; k < j-i+1-K+1; k++) {
                    d = y[k];
                    u = y[k+K-1];
                    if (ans == 0) ans = (u-d)*(r-l);
                    else ans = min(ans, (u-d)*(r-l));
                }
            }
        }
    }
    printf("%ld", ans);
    
}