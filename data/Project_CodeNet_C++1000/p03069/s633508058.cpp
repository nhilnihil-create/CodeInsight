#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int cnt = 0;
    rep(i, N) {
        if (S[i] == '.') ++cnt;
    }
    int ans = cnt;
    rep(i, N) {
        if (S[i] == '.') --cnt;
        else ++cnt;
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
