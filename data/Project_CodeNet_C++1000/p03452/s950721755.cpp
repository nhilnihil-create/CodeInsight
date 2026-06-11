#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef signed long long ll;

int N, M;
vector<pair<int, ll> > e[100000];
bool used[100000];
ll pos[100000];

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int l, r;
        ll d;
        cin >> l >> r >> d;
        l--;
        r--;

        e[l].push_back(make_pair(r, d));
        e[r].push_back(make_pair(l, -d));
    }

    for (int i = 0; i < N; i++) {
        used[i] = false;
    }

    for (int i = 0; i < N; i++) {
        if (used[i]) {
            continue;
        }

        vector<pair<int, ll> > stack;
        stack.push_back(make_pair(i, 0));

        while (!stack.empty()) {
            auto p = stack.back();
            stack.pop_back();
            int i = p.first;
            ll d = p.second;

            if (used[i]) {
                if (pos[i] != d) {
                    cout << "No" << endl;
                    return 0;
                }
            } else {
                used[i] = true;
                pos[i] = d;
                for (int j = 0; j < e[i].size(); j++) {
                    auto to = e[i][j];
                    stack.push_back(make_pair(to.first, d + to.second));
                }
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
