#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, M;
vector<vector<int>> s(10, vector<int> (10));
vector<int> k(10);
vector<int> p(10);

int main() {
    cin >> N >> M;
    for(ll i = 0; i < M; i++) {
        cin >> k.at(i);
        for(ll j = 0; j < k.at(i); j++) {
            cin >> s.at(i).at(j);
        }
    }
    for( ll i = 0; i < M; i++) {
        cin >> p.at(i);
    }

    int res = 0;
    for( int button = 0; button < (1<<N); ++button ) {
        ll count = 0;
        for( int i = 0; i < M; ++i ) {
            ll switch_on = 0;
            for(int j = 0; j < k.at(i); ++j) {
                if (button & (1<<(s.at(i).at(j)-1))) switch_on++;
            }
            if (switch_on % 2 == p.at(i)) count++;
            else break;
        }
        if(count == M) res++;
    }
    cout << res << endl;

    return 0;
}
