#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

int main () {
    int a, b; std::string s;
    std::cin >> a >> b >> s;

    bool f = true;
    for(int i = 0; i < s.size(); i++) {
        if(a != i) {
            if(s[i] == '-') {
                f = false;
            }
        } else {
            if(s[i] != '-') {
                f = false;
            }
        }
    }

    std::string ans = f?"Yes":"No";
    std::cout << ans << "\n";
}