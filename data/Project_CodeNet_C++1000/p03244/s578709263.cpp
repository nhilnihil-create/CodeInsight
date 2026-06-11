#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<int> v(n), l(n/2), r(n/2);
    map<int, int> m_l, m_r;
    rep(i, n) {
        cin >> v[i];
        if (i%2 == 0) {
            //l[i] = v[i];
            m_l[v[i]]++;
        }
        else {
            //r[i] = v[i];
            m_r[v[i]]++;
        }
    }
    int l1 = 0, l2 = 0, r1=0, r2=0;
    int cnt = 0;
    for (auto l : m_l) {
        if (l.second > cnt) {
            cnt = l.second;
            l1 = l.first;
        }
    }
    cnt = 0;
    for (auto l : m_l) {
        if (l.first == l1) continue;
        if (l.second > cnt) {
            cnt = l.second;
            l2 = l.first;
        }
    }
    cnt = 0;
    for (auto r : m_r) {
        if (r.second > cnt) {
            cnt = r.second;
            r1 = r.first;
        }
    }
    cnt = 0;
    for (auto r : m_r) {
        if (r.first == r1) continue;
        if (r.second > cnt) {
            cnt = r.second;
            r2 = r.first;
        }
    }
//      printf("l1=%d r1=%d\n", l1, r1);
//      printf("m_l[%d]=%d m_r[%d]=%d\n", l1, m_l[l1], r1, m_r[r1]);
    if (r1 != l1) {
        cout << (n/2-m_r[r1]) + (n/2 - m_l[l1]) << endl;
        return 0;
    }

    cout << min(n/2-m_l[l1] + n/2-m_r[r2], n/2-m_l[l2] + n/2-m_r[r1])<< endl;
}
