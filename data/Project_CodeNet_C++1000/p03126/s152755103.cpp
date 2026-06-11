#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int N, M, cnt = 0; cin >> N >> M;
    unordered_map<int, int> Map;
    for (int i = 0; i < N; ++i) {
        int K; cin >> K;
        for (int j = 0; j < K; ++j) {
            int a; cin >> a; Map[a]++;
        }
    }
    for (int i = 0; i < M; ++i) if (Map[i + 1] == N) cnt++;
    printf("%d\n", cnt);
}
