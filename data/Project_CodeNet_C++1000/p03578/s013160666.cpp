#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    map<int, int> m;
    for(int i = 0; i < N; i++) {
        int D;
        cin >> D;
        if(m.count(D) == 0)
            m.emplace(D, 1);
        else
            m[D]++;
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int T;
        cin >> T;
        if(m.count(T) == 0) {
            cout << "NO";
            return 0;
        } else {
            m[T]--;
            if(m[T] < 0) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
