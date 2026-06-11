#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <math.h>
#include <sstream>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    std::cin >> a >> b;
    if (a+b == 15) {
        std::cout << "+" << std::endl;
    } else if (a*b == 15) {
        std::cout << "*" << std::endl;
    } else {
        std::cout << "x" << std::endl;
    }
    return 0;
}