#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, r = 0, b = 0;
    scanf("%d", &n);
    vector<char> s(n);
    scanf("%s", s.begin());
    for (int i = 0; i < n; ++i) switch (s.at(i)) {
            case 'R': ++r; break;
            case 'B': ++b; break;
    }
    printf("%s\n", r > b ? "Yes" : "No");
    return 0;
}
