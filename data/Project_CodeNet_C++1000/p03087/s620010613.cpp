#include <iostream>
#include <vector>

int main() {
    int n, q; std::cin >> n >> q;
    std::string s; std::cin >> s;
    std::vector<int> r(n+1);
    std::vector<int> l(n+1);
    int c = 0;
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && s[i] == 'C' && s[i-1] == 'A') {
            c++;
        }
        r[i+1] = c;
        if (i + 1 < n && s[i] == 'A' && s[i+1] == 'C') {
            d--;
        }
        l[i+1] = d;
    }
    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < q; i++) {
        int ll, rr; std::cin >> ll >> rr;
        v.push_back({ll, rr});
    }

    /*
    for (int i = 0 ; i <= n; i++) {
        std::cout << l[i] << " " << r[i] << std::endl;
    }
    //*/

    for (const auto& vv: v) {
        std::cout << (r[vv.second] + l[vv.first-1]) << std::endl;
    }


    return 0;
}