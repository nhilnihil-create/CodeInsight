#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[100001];
int main() {
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    cnt[0] = 0;
    for (int i = 1; i < N; i++) {
        if (s[i-1] == 'A' && s[i] == 'C')
            cnt[i] = cnt[i - 1] + 1;
        else
            cnt[i] = cnt[i - 1];
    }
    for (int i = 0; i < Q; i++) {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        cout << cnt[y] - cnt[x] << endl;
    }
}