#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, M, A, B;
    cin >> N >> M;
    vector<pair<ll, ll>> AB;
    rep(i,N) {
        cin >> A >> B;
        AB.push_back(make_pair(A, B));
    }
    sort(AB.begin(), AB.end());
    int cnt = 0;
    ll price = 0;
    rep(i,N) {
        if (cnt + AB.at(i).second >= M) {
            price += AB.at(i).first * (M - cnt);
            cout << price << endl;
            return 0;
        } else {
            cnt += AB.at(i).second;
            price += AB.at(i).first * AB.at(i).second;
        }
    }
}
