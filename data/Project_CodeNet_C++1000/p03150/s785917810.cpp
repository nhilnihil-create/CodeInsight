#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

ll dist(ll a, ll b, ll c, ll d) {
    return abs(a-c) + abs(b-d);
}

int main() {
    string S;
    char elem[] = {'k', 'e', 'y', 'e', 'n', 'c', 'e'};
    int counter = 0;

    cin >> S;

    if (S == "keyence") {cout << "YES" << endl; return 0;}
    while (S[counter] == elem[counter]) {
        counter++;
    }

    while (S[S.size()-(7-counter)] == elem[counter]) {
        counter++;
    }

    string ans = (counter == 8) ? "YES" : "NO";
    cout << ans << endl;

}
