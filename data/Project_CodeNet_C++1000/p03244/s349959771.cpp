#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    map<int, int> cnt1, cnt2;
    int N, a;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (i % 2) cnt1[a]++;
        else cnt2[a]++;
    }
    vector<pii> v;
    for (auto c : cnt1) v.push_back(pii(c.second, c.first));
    for (auto c : cnt2) v.push_back(pii(c.second, c.first));
    sort(v.begin(), v.end(), greater<pii>());
    int ans = N;
    int cnt = -1;
    for (int i = 0; i < v.size(); i++) {
        if (cnt == -1) {
            ans -= v[i].first;
            cnt = v[i].second;
        }
        else {
            if (cnt == v[i].second) continue;
            ans -= v[i].first;
            break;
        }
    }
    cout << ans << '\n';
}