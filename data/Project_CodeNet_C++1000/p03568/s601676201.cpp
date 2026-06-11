#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 1;
    int bns = 1;
    rep(i, N) {
        ans *= 3;
        int A;
        cin >> A;
        if (A % 2 == 0) bns *= 2;
    }
    cout << ans - bns << endl;
    return 0;
}
