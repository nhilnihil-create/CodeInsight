#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 7;

int v[N], c[2 * N], n;

set < int > s;

bool ok(int val) {
    s.clear();
    for (int i = 1; i < n; ++i) {
        if (v[i] > v[i - 1]) {
            auto it = s.end();
            if (it == s.begin())///nu ai ce sterge dreq
                continue;
            it--;
            while (*it >= v[i - 1]) {///nu stergi ca bou' dreq
                s.erase(it);
                if (it == s.begin())///verifici si tu sa nu tai unghia din carne
                    break;
                it--;
            }
        }
        else {
            for (int j = v[i] - 1; j >= 0; --j) {
                if (s.find(j) == s.end()) {///lowl
                    s.insert(j);
                    c[j] = 1;
                    break;
                }
                else if (c[j] == val - 1) {
                    if (!j)
                        return false;
                    s.erase(j);
                    c[j] = 0;
                }
                else {
                    ++c[j];
                    break;
                }
            }
        }
    }
    return true;
}

int bs() {
    int pas(1<<17), r(1);
    while (pas) {
        if (!ok(r + pas))
            r += pas;
        pas >>= 1;
    }
    return r + 1;
}

int main()
{
    bool cresc(true);
    cin >> n;
    for (int i = 0; i < n; ++i)  {
        cin >> v[i];
        if (i && v[i] <= v[i - 1])
            cresc = false;
        v[i] = min(v[i], 2 * N - 7);
    }
    if (cresc)
        return cout << 1, 0;
    cout << bs();
    return 0;
}
