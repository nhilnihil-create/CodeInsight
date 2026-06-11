#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

int main(){
    int N, K;
    cin >> N >> K;
    vector<ll> h(N);
    for (int i = 0; i < N; i++) cin >> h.at(i);

    ll min_v = 10000000001;
    sort(h.begin(), h.end());
    for (int i = 0; i < N - K + 1; i++) {
        min_v = min(min_v, h.at(i + K - 1) - h.at(i));
    }
    
    cout << min_v << endl;
    return 0;
}