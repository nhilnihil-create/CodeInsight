#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int Max = 0;
int Min = 110;

int water(vector<int> h) {
    rep(i, h.size()) h[i] -= Min;
    int count = Min;
    for(int i = 0; i <= Max; i++) {
        rep(j, h.size()) {
            if(h[j] != 0) {
                h[j]--;
                while(h[j + 1] != 0) {
                    h[j + 1]--;
                    j++;
                }
                count++;
            }
        }
    }
    return count;
}
int main () {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) {
        cin >> h[i];
        Max = max(h[i], Max);
        Min = min(h[i], Min);
    }
    cout << water(h) << endl;
}