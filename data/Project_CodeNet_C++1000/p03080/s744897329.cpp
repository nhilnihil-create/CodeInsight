#include <iostream>
#include <string>

int main()
{
    int n, red=0;
    std::cin >> n;
    char s[n+1];
    std::cin >> s;
    for(int i=0; i<n; i++){
        if(s[i] == 'R') red++;
    }
    if(2*red > n) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
    return 0;
}
