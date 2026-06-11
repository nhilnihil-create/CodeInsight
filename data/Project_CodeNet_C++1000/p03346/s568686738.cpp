#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int,int>> P(N);
    for (int i=0;i<N;i++) {
        int p;
        cin >> p;
        P[i] = make_pair(p, i);
    }
    sort(P.begin(),P.end());
    int mx = 1;
    int s = 1;
    for (int i=1;i<N;i++){
        if (P[i-1].second < P[i].second) mx++;
        else {
            s = max(s, mx);
            mx = 1;
        }
        if (i==N-1) {
            s = max(s,mx);
        }
    }
    cout << N - s << "\n";
}