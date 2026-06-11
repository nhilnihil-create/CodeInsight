#include <bits/stdc++.h>

void delete_if_mono(int i, std::vector<std::set<int>>& red, std::vector<std::set<int>>& black, std::set<int>& remain) {
    if (red[i].size() > 0 && black[i].size() > 0) return;
    remain.erase(i);
    if (red[i].size() == 0 && black[i].size() == 0) {
    } else if (red[i].size() == 0) {
        for (auto to : black[i]) black[to].erase(i);
        for (auto to : black[i]) delete_if_mono(to, red, black, remain);
    } else {
        for (auto to : red[i]) red[to].erase(i);
        for (auto to : red[i]) delete_if_mono(to, red, black, remain);
    }
}

int main() {
    int n, m;
    std::string str;
    std::cin >> n >> m >> str;
    std::vector<bool> c(n);
    for (int i = 0; i < n; i++) c[i] = str[i] == 'A';
    std::vector<std::set<int>> red(n), black(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        if (a < b) std::swap(a, b);
        if (c[a] ^ c[b]) {
            red[a].insert(b);
            red[b].insert(a);
        } else {
            black[a].insert(b);
            black[b].insert(a);
        }
    }

    std::set<int> remain;
    for (int i = 0; i < n; i++) remain.insert(i);
    for (int i = 0; i < n; i++) {
        if (remain.find(i) == remain.end()) continue;
        delete_if_mono(i, red, black, remain);
    }
    std::cout << (remain.size() ? "Yes" : "No") << std::endl;

    return 0;
}
