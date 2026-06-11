#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num, m;
    cin >> num >> m;
    vector<tuple<long long, long long, long long>> tpl;
    vector<pair<long long, long long>> p(m);
    vector<long long> vec(m);
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        tpl.emplace_back(a, b, i);
    }

    sort(begin(tpl), end(tpl));

    long long tmpP = -1;
    long long cnt = 0;
    for (int i = 0; i < m; i++) {
        if (tmpP != get<0>(tpl[i])) {
            tmpP = get<0>(tpl[i]);
            cnt = 1;
        }
        p.at(get<2>(tpl[i])) = make_pair(get<0>(tpl[i]), cnt);
        cnt++;
    }

    for (int i = 0; i < m; i++) {
        cout << setfill('0') << right << setw(6) << p.at(i).first;
        cout << setfill('0') << right << setw(6) << p.at(i).second << endl;
    }

    //
}
