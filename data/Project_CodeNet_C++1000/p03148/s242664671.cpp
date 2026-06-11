#include <bits/stdc++.h>

using namespace std;

struct Taste {
    long long hi;
    vector<long long> ds;
    Taste(): hi(0), ds(0) {}
    void add(long long d) {
        ds.push_back(d);
        hi = max(hi, d);
    }
    bool operator<(const Taste& o) const {
        return hi > o.hi;
    }
};

struct TopK {
    int k;
    multiset<long long> xs;
    long long sum;
    TopK(int k): k(k), sum(0) {}
    void insert(long long x) {
        xs.insert(x);
        sum += x;
        minimize();
    }
    void minimize() {
        while (xs.size() > k) {
            sum -= *xs.begin();
            xs.erase(xs.begin());
        }
    }
    void decrease_k() {
        --k;
        minimize();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<Taste> tastes(n);
    for (int i = 0; i < n; ++i) {
        int t, d;
        cin >> t >> d;
        --t;
        tastes[t].add(d);
    }
    sort(tastes.begin(), tastes.end());
    for (auto& taste : tastes) {
        sort(taste.ds.begin(), taste.ds.end(), [](int i, int j) { return i > j; });
    }
    long long best = 0;
    long long sum = 0;
    long long x = 0;
    TopK top_k(k);
    for (auto& taste : tastes) {
        if (taste.hi > 0 && x < k) {
            top_k.decrease_k();
            ++x;
            sum += taste.hi;
            for (int i = 1; i < (int) taste.ds.size(); ++i) {
                top_k.insert(taste.ds[i]);
            }
            best = max(best, sum + x*x + top_k.sum);
        }
    }
    cout << best << endl;
    return 0;
}
