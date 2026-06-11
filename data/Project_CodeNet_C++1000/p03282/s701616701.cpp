#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    string s;
    ll k, i=0;
    cin >> s >> k;

    while(true) {
        if(s[i] == '1') i++;
        else break;
    }
    if(i < k) cout << s[i] << endl;
    else cout << 1 << endl;
}