#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> veci;
typedef vector<long long> vecll;
typedef vector<unsigned long long> vecull;

int N;
int main(void) {
    cin >> N;
    veci b(N);
    rep(i, N) {
        cin >> b[i];
        b[i]--;
    }

    bool flag = true;

    stack<int> ans;
    while (b.size() != 0) {
        int k = -1;
        for (int i = 0; i < b.size(); ++i) {
            if (b[i] == i) {
                k = i;
            }
        }

        if (k == -1) {
            flag = false;
            break;
        }

        ans.push(k);
        b.erase(b.begin() + k);
    }

    if (!flag) {
        cout << -1 << endl;
        return 0;
    }

    while (!ans.empty()) {
        cout << ans.top() + 1 << endl;
        ans.pop();
    }
    return 0;
}