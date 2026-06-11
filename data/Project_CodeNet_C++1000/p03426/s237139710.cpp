#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const int int_inf = 100000000;
const double eps = 1e-9;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int h, w, d, q;
    cin >> h >> w >> d;

    vector<vector<tuple<int, int, int>>> x(d);
    int tmp;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> tmp;
            x[tmp%d].push_back(make_tuple(tmp, i+1, j+1));
        }
    }

    cin >> q;
    vector <int> l(q), r(q);
    for (int i = 0; i < q; i++) cin >> l[i] >> r[i];

    for (int i = 0; i < d; i++) sort(x[i].begin(), x[i].end());

    vector<vector<int>> sum(d);

    for (int i = 0; i < d; i++) {
        sum[i].push_back(0);
        tmp = 0;
        for (int j = 0; j < int(x[i].size()); j++) {
            sum[i].push_back(abs(get<1>(x[i][j+1]) - get<1>(x[i][j])) + abs(get<2>(x[i][j+1]) - get<2>(x[i][j])) + tmp);
            tmp += abs(get<1>(x[i][j+1]) - get<1>(x[i][j])) + abs(get<2>(x[i][j+1]) - get<2>(x[i][j]));
        }
    }
    /*
    for (int i = 0; i < d; i++) {
        cout << i << " : ";
        for (int j = 0; j  < sum[i].size(); j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (int i = 0; i < q; i++) {
        tmp = r[i]%d;
        int r_idx = (r[i]-1)/d;
        //cout << r_idx << endl;
        int l_idx = (l[i]-1)/d;
        //cout << l_idx << endl;
        cout << sum[tmp][r_idx] - sum[tmp][l_idx] << endl;
    }


    return 0;
}

