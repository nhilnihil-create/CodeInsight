#include <iostream>
#include <utility>
#include <algorithm>

const int MAX = 1000001;

using namespace std;

pair<int, int> p[MAX];
int a[MAX];

int main() {
    unsigned long long sum = 0;
    int n, m, b, c;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> p[i].second >> p[i].first;
    }
    sort(a, a + n);
    sort(p, p + m);

    int cnt = 0;
    for (int i = m - 1; i > -1; --i) {
        b = p[i].second;
        c = p[i].first;

        while (b && cnt >= 0) {
            if (a[cnt] < c)
                a[cnt] = c;
            else break;
            --b;
            ++cnt;
        }
    }

    for(int i = 0;i < n; ++i){
        sum += a[i];
    }
    cout << sum << endl;
}