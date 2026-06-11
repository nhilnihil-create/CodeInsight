#include <algorithm>
#include <cstdio>

const int N = 100000;

char buf[N + 1];

int main()
{
#ifdef LOCAL_JUDGE
    freopen("B.in", "r", stdin);
#endif
    while (scanf("%s", buf) == 1) {
        int cnt[] = {0, 0, 0};
        for (int i = 0; buf[i]; ++ i) {
            cnt[buf[i] - 'a'] ++;
        }
        std::sort(cnt, cnt + 3);
        bool ok = false;
        ok |= cnt[0] == cnt[1] && cnt[0] == cnt[2];
        ok |= cnt[0] == cnt[1] && cnt[0] + 1 == cnt[2];
        ok |= cnt[0] + 1 == cnt[1] && cnt[0] + 1 == cnt[2];
        puts(ok ? "YES" : "NO");
    }
}
