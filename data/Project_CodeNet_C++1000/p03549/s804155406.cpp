#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int N , M , ans = 1;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        ans*=2;
    }
    cout << (1900 * M + 100 * (N - M)) * ans << endl;
}