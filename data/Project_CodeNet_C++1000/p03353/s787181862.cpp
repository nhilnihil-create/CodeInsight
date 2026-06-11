#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string s;
    int K;
    cin >> s >> K;
    
    vector<string> S;
    rep(i, s.size()) {
        rep(j, min((int)s.size() - i, K)) {
            S.push_back(s.substr(i, j + 1));
        }
    }
    sort(S.begin(), S.end());
    int cnt = 0;
    rep(i, S.size()) {
        if (!binary_search(S.begin(), S.begin() + i, S[i])) ++cnt;
        if (cnt == K) {
            cout << S[i] << endl;
            return 0;
        }
    }
}
