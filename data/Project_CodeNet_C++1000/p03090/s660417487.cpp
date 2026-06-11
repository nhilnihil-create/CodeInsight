#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int N;
    cin >> N;

    vector<P> E;
    if (N % 2) {
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                if (i + j == N) continue;
                E.push_back( P(i, j) );
            }
        }
    } else {
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                if (i + j == N + 1) continue;
                E.push_back( P(i, j) );
            }
        }
    }

    cout << E.size() << endl;
    for (auto p : E) {
        printf("%d %d\n", p.first, p.second);
    }
}