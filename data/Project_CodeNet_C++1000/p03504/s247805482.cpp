#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//imos法というものがあるらしい。程度は違うが同じことしようとしてた
int main() {
    int N, C; cin >> N >> C;
    vector<vector<int>> imos(30, vector<int> (200001, 0));
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a *= 2; b *= 2; a--; c--;
        imos[c][a] ++;
        imos[c][b] --;
    }
    for (int i = 0; i < C; i++) {
        for (int j = 1; j < 200001; j++) {
            imos[i][j] += imos[i][j-1];
        }
    }
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < 200001; j++) {
            if (imos[i][j]) imos[i][j] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < 200001; i++) {
        int val = 0;
        for (int j = 0; j < C; j++) {
            val += imos[j][i];
        }
        ans = max(ans, val);
    }
    cout << ans << endl;
}