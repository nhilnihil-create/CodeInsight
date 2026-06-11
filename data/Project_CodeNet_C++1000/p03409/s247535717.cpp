// わからん
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define print(x) cout << x << endl;
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> ab, cd;

    int x, y;
    rep(i, N) {
        cin >> x >> y;
        ab.push_back(pair<int, int>(x, y));
    }    
    rep(i, N) {
        cin >> x >> y;
        cd.push_back(pair<int, int>(x, y));
    }    

    sort(cd.begin(), cd.end(), [](const pair<int, int> x, const pair<int, int> y){return x.first < y.first;});
    
    int done[N] = {};
    int sum = 0;

    rep(i, N) {
        int max_y = -1;
        int max_ind = -1;
        rep(j, N) {
            if (ab.at(j).first < cd.at(i).first && ab.at(j).second < cd.at(i).second) {
                if (ab.at(j).second > max_y && done[j] == 0) {
                    max_ind = j;
                    max_y = ab.at(j).second;
                }
            }
        }
        if (max_ind == -1) continue;
        else {
            done[max_ind] += 1;
            sum++;
        }
    }

    cout << sum << endl;
    
    return 0;
}