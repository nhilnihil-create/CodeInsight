#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main() {
    int l, cnt = 0;
    scanf("%d", &l);
    int i = 1;
    vector< vector < pair<int, int> > > e(1);
    for (; (1 << i) - 1 < l; ++i) {
        e.push_back({});
        e.at(i).push_back({i + 1, 0}), e.at(i).push_back({i + 1, 1 << (i - 1)}), cnt += 2;
    }
    int n = i, prev = (1 << (n - 1));
    for (--i; i >= 1; --i) if (l > prev + (1 << (i - 1)) - 1) e.at(i).push_back({n, prev}), prev += (1 << (i - 1)), ++cnt;
    printf("%d %d\n", int(e.size()), cnt);
    for (int i = 1; i < n; ++i) for (int j = 0; j < int(e.at(i).size()); ++j) printf("%d %d %d\n", i, e.at(i).at(j).first, e.at(i).at(j).second);
    return 0;
}
