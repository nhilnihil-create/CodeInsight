#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=acos(-1);

int main () {
    int N,M;
    cin >> N;
    int D[N];
    rep(i,N) {
        cin >> D[i];
    }

    cin >> M;

    map<int,int64_t> T;

    rep(i,M) {
        int tmp; cin >> tmp;
        if(!T.count(tmp)) {
            T[tmp] = 1;
        }
        else {
            T[tmp]++;
        }
    }
    string ans = "YES";
    rep(i,N){
        if (T.count(D[i])) {
            T[D[i]]--;
        }
    }
    for (auto p: T) {
        auto key = p.first;
        auto value = p.second;
        if (value >0) {
            ans = "NO";
        }
    }
    cout << ans << endl;
}