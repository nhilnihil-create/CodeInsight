#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> V(N+1);
    set<int> W;

    for(int i=1; i<=N; i++) {
        int a;
        cin >> a;
        V[a]++;
        W.insert(a);
    }
    int d = W.size() - K;

    if(d <= 0) {
        cout << 0 << endl;
        return 0;
    }

    int count = 0;
    sort(V.begin(), V.end());
    for(int i=1; i<=N; i++) {
        if(V[i] != 0) {
            count += V[i];
            d--;
        }
        if(d <= 0) {
            break;
        }
    }

    cout << count << endl;


}