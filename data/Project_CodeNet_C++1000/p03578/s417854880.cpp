#include <iostream>
#include <vector>

int main()
{
    int n; std::cin >> n;
    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    int m; std::cin >> m;
    std::vector<int> t(m);
    for (int j = 0; j < m; j++) {
        std::cin >> t[j];
    }

    std::sort(d.begin(), d.end());
    std::sort(t.begin(), t.end());

    bool b = true;
    size_t dd = 0, tt = 0;
    while (dd < d.size() && tt < t.size()) {
        if (d[dd] == t[tt]) {
            dd++; tt++;
        } else if (d[dd] < t[tt]) {
            dd++;
        } else {
            b = false;
            break;
        }
    }
    if (tt < t.size()) {
        b = false;
    }
    std::cout << (b?"YES":"NO") << std::endl;


    return 0;
}
