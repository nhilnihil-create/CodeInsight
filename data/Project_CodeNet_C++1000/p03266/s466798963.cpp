#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void judge(int &i, unordered_map<char, char> &map, string &S1, string &S2, string &ans) {
    if (map.count(S1.at(i)) == 1 && map[S1.at(i)] != S2.at(i)) {
        ans = "No";
    } else map[S1.at(i)] = S2.at(i);
}

int main() {
    int N, K;
    cin >> N >> K;
    ll mod0 = N / K;
    ll modhalf;
    if (K % 2 == 1) modhalf = 0;
    else {
        modhalf = mod0;
        if (N % K >= K / 2) ++modhalf;
    }
    ll ans = mod0*mod0*mod0 + modhalf*modhalf*modhalf;
    cout << ans << endl;
}
