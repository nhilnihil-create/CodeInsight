#include <iostream>
#include <vector>
#include <set>
#include <cmath>

#define rep(a, b) for (int (a) = 0; (a) < (b); (a)++)

using namespace std;

long long solve(multiset<pair<int, int>> st1, multiset<pair<int, int>> st2, bool flag) {
    long long ret = 0;

    int pt = 0;
    while (true) {
        if (!flag) {
            if (st1.empty()) break;
            pair<int, int> pr = *st1.rbegin();
            ret += max(0, pr.first - pt);
            if (pr.first < pt) break;
            pt = pr.first;
            st1.erase(st1.find(pr));
            st2.erase(st2.find(make_pair(pr.second, pr.first)));
        } else flag = false;

        if (st2.empty()) break;
        pair<int, int> pr = *st2.begin();
        ret += max(0, pt - pr.first);
        if (pr.first > pt) break;
        pt = pr.first;
        st1.erase(st1.find(make_pair(pr.second, pr.first)));
        st2.erase(st2.find(pr));
    }
    
    ret += abs(pt);
    
    return ret;
}

int main() {
    int N;
    cin >> N;

    multiset<pair<int, int>> st1, st2;
    rep(i, N) {
        int L, R;
        cin >> L >> R;

        st1.insert(make_pair(L, R));
        st2.insert(make_pair(R, L));
    }

    long long ret = solve(st1, st2, false);
    ret = max(ret, solve(st1, st2, true));

    cout << ret << endl;

    return 0;
}
