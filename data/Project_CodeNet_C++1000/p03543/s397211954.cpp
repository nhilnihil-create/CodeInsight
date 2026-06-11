#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    std::cin >> n;
    if (n[0] == n[1] && n[1] == n[2]){
        std::cout << "Yes" << std::endl;
    }
    else if (n[1] == n[2] && n[2] == n[3]){
        std::cout << "Yes" << std::endl;
    }
    else{
        std::cout << "No" << std::endl;
    }
}