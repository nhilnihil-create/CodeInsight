#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<P> ab(N);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        ab[i] = P {x, y};
    }
    vector<P> cd(N);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        cd[i] = P {x, y};
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    int abi = N-1;
    int ans = 0;
    /*
    cout << "Coutn" << endl;
    for (int i=N-1; i>=0; --i) {
        cout << "cd: " << cd[i].first << " " << cd[i].second << endl;
        // c = cd[i].first;
        // d = cd[i].second;
        for (int j=ab.size()-1; j>=0; --j) {
            if (cd[i].first > ab[j].first && cd[i].second > ab[j].second) {
                cout << "ab: " << ab[j].first << " " << ab[j].second << endl;
                ans += 1;
                // abi = j-1;
                break;
            }
        }
    }*/
    rep(i, N) {
        P match_i = {0, -1};
        int temp_j = N;
        // cout << "cd: " << cd[i].first << " " << cd[i].second << endl;
        // rep(j, ab.size()) cout << ab[j].first << " " << ab[j].second << endl;
        rep(j, ab.size()) {
            if (cd[i].first > ab[j].first && cd[i].second > ab[j].second && ab[j].second > match_i.second) {
                match_i = ab[j];
                temp_j = j;
            }
        }
        if (temp_j != N) {
            // cout << "ab: " << match_i.first << " " << match_i.second << endl;
            ab.erase(ab.begin()+temp_j);
            ans += 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}