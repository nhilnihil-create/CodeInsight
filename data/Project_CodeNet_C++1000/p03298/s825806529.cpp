#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;
string S;

int main() {
    cin >> N >> S;
    map<pair<string, string>, int> mp;
    for (int i = 0; i < (1 << N); i++) {
        string a = "", b = "";
        for (int j = 0; j < N; j++) {
            if (1 << j & i) {
                a += S[j];
            } else {
                b += S[j];
            }
        }
        mp[make_pair(a, b)] += 1;
    }
    long long ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        string a = "", b = "";
        for (int j = 0; j < N; j++) {
            if (1 << j & i) {
                a += S[2 * N - 1 - j];
            } else {
                b += S[2 * N - 1 - j];
            }
        }
        ans += mp[make_pair(a, b)];
    }
    cout << ans << endl;
}