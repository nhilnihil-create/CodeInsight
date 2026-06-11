#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    map<int,int> DM;
    rep(i,N) {
        int d; cin >> d;
        DM[d]++;
    }

    int M; cin >> M;
    vector<int> T(M);
    rep(i,M) {
        cin >> T.at(i);
        if (DM[T[i]] > 0) DM[T[i]]--;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
