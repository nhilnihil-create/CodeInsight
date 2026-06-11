#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N, M;
    string s, t;
    map<string, int> S, T;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (!S.count(s)) S[s] = 1;
        else S[s]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> t;
        if (!T.count(t)) T[t] = 1;
        else T[t]++;
    }
    int Max = 0;
    for (auto p: S) {
        string u = p.first;
        int v = p.second;
        int m = v;
        if (T.count(u)) m -= T[u];
        Max = max(Max, m);
    }
    cout << Max << endl;
    return 0;
}