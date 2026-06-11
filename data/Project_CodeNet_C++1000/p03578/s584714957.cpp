#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(_) cerr << #_ << ": " << (_) << '\n'
#define _GLIBCXX_DEBUG
#else
#define debug(_) (void(0))
#endif  // LOCAL

int main(){
    int N, M, tmp;
    multiset<int> Ds, Ts;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        Ds.insert(tmp);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        Ts.insert(tmp);
    }
    for (auto T: Ts) {
        debug(T);
        auto it = Ds.find(T);
        if (it == Ds.end()) {
            cout << "NO\n";
            return 0;
        }
        Ds.erase(it);
    }

    cout << "YES\n";

    return 0;
}