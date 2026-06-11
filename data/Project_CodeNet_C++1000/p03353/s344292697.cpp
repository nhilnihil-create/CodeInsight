#include <bits/stdc++.h>
#define ll long long
int main()
{
    std::string s;
    int k;

    std::cin >> s >> k;
    std::vector<std::string> Ans(k, "ああああ");
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 1; i + j <= s.size(); ++j) {
            bool flag_1 = false;
            for (int l = 0; l < k; ++l) {
                if (Ans.at(l).compare(s.substr(i, j)) == 0) {
                    break;
                } else if (Ans.at(l).compare(s.substr(i, j)) > 0) {
                    Ans.insert(Ans.begin() + l, s.substr(i, j));
                    break;
                } else {
                    if (l == k - 1) {
                        flag_1 = true;
                        //std::cout << "null" << std::endl;
                    }
                    //std::cout << Ans[k - 1] << std::endl;
                }
            }
            if (flag_1) {
                break;
            }
        }
    }
    std::cout << Ans[k - 1] << std::endl;
}