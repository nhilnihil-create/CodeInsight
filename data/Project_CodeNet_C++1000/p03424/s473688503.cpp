#include<iostream>
#include<string>
#include<vector>
#include<set>

int main () {
    int n;
    std::cin >> n;

    std::set<char> s;
    for (int i = 0; i < n;i ++ ) {
        char a;
        std::cin >> a;
        s.insert(a);
    }

    std::string ans = s.size() == 3 ? "Three" : "Four";
    std::cout << ans << "\n";
}