#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {
    
    int N;
    cin >> N;
    vector<P> red(N), blue(N);
    rep(i,N) cin >> red[i].first >> red[i].second;
    rep(i,N) cin >> blue[i].first >> blue[i].second;

    vector<pair<int, P>> pairs;

    sort(red.begin(), red.end(), [](const P& x, const P& y) {return x.second > y.second;});
    sort(blue.begin(), blue.end(), [](const P& x, const P& y) {return x.first < y.first;});

    vector<bool> r(N, false);

    int count = 0;

    rep(i,N) {
        rep(j,N) {
            if (!r[j] && blue[i].first > red[j].first && blue[i].second > red[j].second) {
                count++;
                r[j] = true;
                break;
            }
        }
    }

    cout << count << endl;

}