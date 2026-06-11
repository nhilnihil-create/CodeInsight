#include<iostream>
#include<string>
#include<vector>

int main() {
    int a, b; std::cin >> a >> b;

    int ans = 0;
    for(int i = a; i <= b; i++) {
        std::string num = std::to_string(i);

        bool f = true;
        for(int j = 0; j < num.size() / 2; j++) {
            if(num[j] != num[num.size() - 1 - j]) {
                f = false;
            }
        }

        if(f) {
            ans ++;
        }
    }

    std::cout << ans << "\n";
}