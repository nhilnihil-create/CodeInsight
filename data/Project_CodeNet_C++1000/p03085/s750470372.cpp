#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

int main(){
    std::string s;
    std::cin >> s;

    if (s == "A")
    {
        s = "T";
    }
    else if (s == "C")
    {
        s = "G";
    }
    else if (s == "G")
    {
        s = "C";
    }
    else
    {
        s = "A";
    }
    
    std::cout << s << std::endl;

    return 0;
}