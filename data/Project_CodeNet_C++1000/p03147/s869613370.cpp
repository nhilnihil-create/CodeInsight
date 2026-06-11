#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> h(110), ch(110, 0);

int solve(int l, int r) {
    int mini = 1000;
    for (int i = l; i < r; i++) {
        mini = min(h[i], mini);
    }

    int ans = mini;
    int nr, nl = l;
    for (int i = l; i < r; i++) {
        h[i] -= mini;
        if (h[i] == 0) {
            nr = i;
            if (nl < nr) ans += solve(nl, nr);
            nl = i+1;
        }
    }
    if (nl < r) ans += solve(nl, r);
    return ans;
}

int main() {

    cin >> n;
    for(int i = 0; i < n; i++) cin >> h[i];
    cout << solve(0, n) << endl;
}