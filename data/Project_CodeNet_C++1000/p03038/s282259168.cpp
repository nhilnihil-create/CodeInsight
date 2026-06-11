#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num, que;

    cin >> num >> que;
    map<long long, long long> m;
    vector<pair<long long, long long>> p(que);
    for (long long i = 0; i < num; i++) {
        long long tmp;
        cin >> tmp;
        m[tmp]++;
    }

    for (long long i = 0; i < que; i++) {
        long long a, b;
        cin >> a >> b;
        p.at(i) = make_pair(b, a);
    }
    sort(p.rbegin(), p.rend());

    for (long long i = 0; i < que; i++) {
        long long cnt = 0;
        for (auto itr : m) {
            if (itr.second == 0) continue;
            if (p.at(i).second == 0 || itr.first >= p.at(i).first) break;

            //cout << "itr:" << itr.first << ":" << itr.second << endl;
            //cout << "p  :" << p.at(i).first << ":" << p.at(i).second;
            if (p.at(i).second >= itr.second) {
                m[p.at(i).first] += itr.second;
                m[itr.first] = 0;
                p.at(i).second -= itr.second;
                // m.erase(begin(m));
                cnt++;
            } else {
                m[p.at(i).first] += p.at(i).second;
                m[itr.first] -= p.at(i).second;
                p.at(i).second = 0;
            }
            //cout << "->" << p.at(i).first << ":" << p.at(i).second << endl;
        }
        if (cnt > 0) m.erase(begin(m), next(begin(m), cnt));
    }

    long long kekka = 0;
    for (auto itr : m) {
        // cout << (long long)itr.first << "*" << (long long)itr.second << endl;
        kekka += (itr.first * itr.second);
    }

    cout << kekka << endl;
    //
}
