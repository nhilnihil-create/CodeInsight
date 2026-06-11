#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    int k;
    vector<vector<int>> s(M, vector<int>(N, 0));
    for(int i = 0; i < M; i++) {
        cin >> k;
        for(int j = 0; j < k; j++) {
            int t;
            cin >> t;
            t--;
            s[i][t] = 1;
        }
    }
    vector<int> p(M);
    for(int i = 0; i < M; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for(int bit = 0; bit < (1 << N); bit++) {
        int lit = 0;
        for(int l = 0; l < M; l++) {
            int count = 0;
            for(int sw = 0; sw < N; sw++) {
                if(bit >> sw & 1 && s[l][sw] == 1) {
                    count++;
                }
            }
            if(count % 2 == p[l]) lit++;
        }
        if(lit == M) ans++;
    }
    cout << ans << endl;
    return 0;
}