#include<iostream>
#include<string>
#include<vector>
#include<set>

int main () {
    int n;
    std::cin >> n;
    std::vector<std::string> w(n);
    std::set<std::string> ws;
    for (int i = 0; i < n; i++)
    {
        std::cin >> w[i];
        ws.insert(w[i]);
    }

    bool f1 = ws.size() == n ? true : false;
    bool f2 = true;
    for (int i = 0; i < n - 1; i++)
    {
        if(w[i][w[i].size()-1] != w[i+1][0]) {
            f2 = false;
        }
    }

    std::string ans = (f1 && f2) ? "Yes" : "No";
    std::cout << ans << "\n";
}