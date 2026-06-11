#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long K, N;
    cin >> N >> K;
    map<long long, vector<long long> > t2vecd;
    for (long long i = 0; i < N; ++i) {
        long long ttemp, dtemp;
        cin >> ttemp >> dtemp;
        if (t2vecd.count(ttemp) == 0) {
            t2vecd.insert(make_pair(ttemp, vector<long long>()));
        }
        t2vecd[ttemp].push_back(dtemp);
    }

    vector<long long> maxDeliForEachType;
    vector<long long> otherDeli;
    for (auto e : t2vecd) {
        sort(e.second.begin(), e.second.end(), greater<long long>());
        for (long long i = 0; i < e.second.size(); ++i) {
            if (i == 0LL) {
                maxDeliForEachType.push_back(e.second[0]);
            }
            else {
                otherDeli.push_back(e.second[i]);
            }
        }
    }
    sort(maxDeliForEachType.begin(), maxDeliForEachType.end(), greater<long long>());
    sort(otherDeli.begin(), otherDeli.end(), greater<long long>());

    long long ans = 0LL;
    for (long long ntopping = 1; ntopping <= maxDeliForEachType.size(); ++ntopping) {
        if (ntopping <= K) {
            if (K - ntopping <= otherDeli.size()) {
                long long temp = accumulate(maxDeliForEachType.begin(), maxDeliForEachType.begin() + ntopping, 0LL);
                temp += accumulate(otherDeli.begin(), otherDeli.begin() + (K - ntopping), 0LL);
                temp += ntopping * ntopping;
                ans = max(temp, ans);
            }
            else {
                continue;
            }
        }
        else {
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
