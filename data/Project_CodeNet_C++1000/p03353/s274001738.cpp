#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    string s;
    cin >> s;
    int K;
    cin >> K;
    map<string, int> ma;
    int N = s.size();
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            string ss = s.substr(i, j);
            ma[ss] = 1;
        }
    }

    int i = 0;
    for (auto m : ma) {
        if (i == K - 1) {
            cout << m.first << endl;
            return 0;
        }
        i++;
    }
}