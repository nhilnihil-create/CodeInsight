#include <iostream>
#include <vector>

int main()
{
    int n, q;
    std::string s;
    std::cin >> n >> q >> s;
    std::vector<int> cnt(n, 0);
    for (int i=1; i<n; ++i)
    {
        cnt[i] = cnt[i-1];
        if (s[i-1] == 'A' && s[i] == 'C')
        {
            cnt[i]++;
        }
    }
    std::vector<int> ans;
    for (int i=0; i<q; ++i)
    {
        int l, r;
        std::cin >> l >> r;
        l--; r--;
        ans.push_back(cnt[r] - cnt[l]);
    }
    for (int i: ans)
    {
        std::cout << i << std::endl;
    }
}