#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

int n, a, b;
deque <int> d;

int main() {

    scanf("%d", &n);
    scanf("%d %d", &a, &b);

    if (1ll * a * b < n || a + b > n + 1) {
        puts("-1");
        return 0;
    }

    for (int i = 1; i <= a; i++)
        d.push_back(i);

    int num = a + 1;
    for (int i = 1; i <= b - 1; i++) {
        int len = (n - a) / (b - 1);
        if (i <= (n - a) % (b - 1))
            len++;

        for (int j = num + len - 1; j >= num; j--)
            d.push_front(j);

        num = num + len;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", d.front());
        d.pop_front();
    }
    cout << endl;

    return 0;
}
