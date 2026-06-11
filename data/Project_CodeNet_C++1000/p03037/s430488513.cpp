#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N, M;
    cin >> N >> M;
    int min_n = 0, max_n = 100000;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        min_n = max(a, min_n);
        max_n = min(b, max_n);
    }
    cout << max(max_n - min_n + 1, 0) << endl;
}