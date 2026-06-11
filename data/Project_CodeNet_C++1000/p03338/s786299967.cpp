#include <algorithm>
#include <iostream>
#include <string>
int main() {
    using std::cin;
    using std::string;

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        string f = s.substr(0UL, i);
        string r = s.substr(i);

        // 各々の重複を削除
        std::sort(f.begin(), f.end());  // Θ(n * n log n)
        std::sort(r.begin(), r.end());
        f.erase(std::unique(f.begin(), f.end()), f.end());
        r.erase(std::unique(r.begin(), r.end()), r.end());

        int duplications = 0;
        for (char fc : f) {  // 𝑶(n * n/2 * n/2)
            if (r.find(fc) != string::npos) duplications++;
        }
        ans = std::max(ans, duplications);
    }

    std::cout << ans << "\n";
    return 0;
}