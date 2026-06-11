#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi   = vector<int>;
using vll  = vector<ll>;
using vc   = vector<char>;
using vvll  = vector<vll>;
using vvi  = vector<vi>;
using vvc  = vector<vc>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;


int main() {
    int N, M; cin >> N >> M;
    int tmp_min=1, tmp_max=N;
    vector<pii> ID;
    for (int i = 0; i < M; i++) {
        int tmpL, tmpR; cin >> tmpL >> tmpR;
        ID.push_back(make_pair(tmpL, tmpR));
    }
    sort(ID.begin(), ID.end());


    for (auto x : ID) {
        int tmpL, tmpR;
        tie(tmpL, tmpR) = x;
        if (tmp_min < tmpL) tmp_min = tmpL;
        if (tmpR < tmp_max) tmp_max = tmpR;
    }
    if (tmp_max < tmp_min) cout << 0 << endl;
    else    cout <<  tmp_max - tmp_min +1 << endl;

}