#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    cin >> k;
    vector<int64_t> A(k);
    copy_n(istream_iterator<int64_t>(cin), k, A.begin());

    auto check = [&](int64_t n, bool s){
        for (const auto &a: A)
            n = n / a * a;
        return s ? n >= 2 : n <= 2;
    };

    int64_t l = -1, r = 2 + k * 1e9;
    while (r - l > 1){
        auto mid = (l + r) / 2;
        if (check(mid, false))
            l = mid;
        else 
            r = mid;
    }
    auto high = l;
    l = -1, r = 2 + k * 1e9;
    while (r - l > 1){
        auto mid = (l + r) / 2;
        if (check(mid, true))
            r = mid;
        else 
            l = mid;
    }

    auto low = r;
    if (high < low)
        cout << -1 << endl;
    else
        cout << low << " " << high << endl;
}