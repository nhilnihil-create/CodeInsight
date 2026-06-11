#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::set<int> as;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        as.insert(a[i]);
    }

    std::sort(a.begin(), a.end());
    int ans = 0;
    std::vector<int> am;
    if (as.size() > k)
    {
        for (auto itr = as.begin(); itr != as.end(); itr++) {
            int num = std::upper_bound(a.begin(), a.end(), *itr) - std::lower_bound(a.begin(), a.end(), *itr);
            am.push_back(num);
        }

        std::sort(am.begin(), am.end());

        for (int i = 0; i < as.size() - k; i++) {
            ans += am[i];
        }
    }

    std::cout << ans << "\n";
}