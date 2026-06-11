#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    
    vector<int> s;
    int cnt = 1;
    REP(i, N) {
        if (S[i - 1] == S[i]) {
            ++cnt;
        } else {
            s.push_back(cnt);
            cnt = 1;
        }
    }
    s.push_back(cnt);
    vector<int> v(s.size());
    if (S[0] == '0') {
        rep(i, v.size()) v[i] = !(i % 2);
    } else {
        rep(i, v.size()) v[i] = i % 2;
    }
    
    int right = 0;
    int k = 0;
    int sum = 0;
    int ans = 0;
    rep(left, s.size()) {
        while (right < s.size() && k + v[right] <= K) {
            sum += s[right];
            k += v[right];
            ++right;
        }
        ans = max(ans, sum);
        if (right == left) {
            ++right;
        } else {
            sum -= s[left];
            k -= v[left];
        }
    }
    cout << ans << endl;
    return 0;
}
