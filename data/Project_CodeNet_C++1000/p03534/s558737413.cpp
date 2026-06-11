#include <cstdio>
#include <algorithm>

static const int MAXN = 1e5 + 4;

static int a = 0, b = 0, c = 0;

int main()
{
    bool finished = false;
    while (!finished) switch (getchar()) {
        case 'a': ++a; break;
        case 'b': ++b; break;
        case 'c': ++c; break;
        default: finished = true; break;
    }

    int cyc = (a + b + c) / 3;
    if ((a -= cyc) < 0 || (b -= cyc) < 0 || (c -= cyc) < 0) {
        puts("NO"); return 0;
    }
    if (std::max(std::max(a, b), c) > 1) {
        puts("NO"); return 0;
    }

    puts("YES"); return 0;
}
