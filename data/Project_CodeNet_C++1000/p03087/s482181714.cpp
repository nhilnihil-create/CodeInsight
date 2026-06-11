#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf (1 << 21)
#define mod 1000000007

int main() {
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    vector<int> cnt(N); //i文字目までにACが何回登場したかを記録する配列
    for (int i = 1; i < N; i++) {
        cnt.at(i) = cnt.at(i - 1);
        if (S.at(i) == 'C' && S.at(i - 1) == 'A') {
            cnt.at(i)++;
        }
    }
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r;
        cout << cnt.at(r - 1) - cnt.at(l - 1) << endl;
    }
    return 0;
}
