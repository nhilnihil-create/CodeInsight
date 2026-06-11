#include <bits/stdc++.h>
using namespace std;
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
int main() {
    string s;
    cin >> s;
    int N = s.length();
    vector<int> v(1);
    for(auto x : s) v.push_back(x == '1');
    bool ans_judge = true;
    ans_judge &= v[1] == 1 && v[N] == 0;
    for(int i = 1; i < N; i++) {
        ans_judge &= v[i] == v[N - i];
    }
    if(!ans_judge) {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int>> ans;
    int pivot = 0;
    for(int i = 1; i < N; i++) {
        ans.push_back(make_pair(pivot, i));
        if(i <= N / 2 && v[i]) pivot = i;
    }
    for(auto x : ans) {
        int u, v;
        tie(u, v) = x;
        u++, v++;
        cout << u << " " << v << endl;
    }
    return 0;
}