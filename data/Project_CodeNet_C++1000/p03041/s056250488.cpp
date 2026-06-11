#include <iostream>

int main(){
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;

    if (s[k - 1] == 'A')
    {
        std::cout << s.replace(k - 1, 1, "a") << std::endl;
    }
    else if (s[k - 1] == 'B')
    {
        std::cout << s.replace(k - 1, 1, "b") << std::endl;
    }
    else
    {
        std::cout << s.replace(k - 1, 1, "c") << std::endl;
    }
    
    return 0;
}