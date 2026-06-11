#include<iostream>
#include<vector>
#include<string>
#include<set>

int main () {
    int n;
    std::string s;
    std::cin >> n >> s;

    int ans = 0;
    int cnt;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        std::set<char> x;
        std::set<char> y;
        for (int j = 0; j < n; j++)
        {
            if(j <= i) {
                x.insert(s[j]);
            } else {
                y.insert(s[j]);
            }
        }

        for (int j = 'a'; j <= 'z'; j++) {
            if(x.find((char)(j))!= x.end() && y.find((char)(j)) != y.end()) {
                cnt++;
            }
        }

        ans = std::max(ans, cnt);
    }

    std::cout << ans << "\n";

}