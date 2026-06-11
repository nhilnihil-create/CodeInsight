#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<tuple<int, int, int>> t(5);

    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        t.at(i) = make_tuple(x, (((x + 9) / 10) * 10), ((10 - (x % 10)) % 10));
    }

    sort(t.begin(), t.end(), [](auto &a, auto &b){
        return get<2>(a) < get<2>(b);
    });

    //for (auto &x : t)
    //    cout << get<0>(x) << ',' << get<1>(x) << ',' << get<2>(x) << endl;

    int s = 0;
    for (int i = 0; i < 4; i++) {
        s += get<1>(t.at(i));
    }

    s += get<0>(t.at(4));

    cout << s << endl;
}