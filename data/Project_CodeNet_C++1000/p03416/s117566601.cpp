#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool kaibun(int i)
{
    int a, b, c, d, e;
    e = i % 10;
    i = (i - e) / 10;
    d = i % 10;
    i = (i - d) / 10;
    c = i % 10;
    i = (i - c) / 10;
    b = i % 10;
    i = (i - b) / 10;
    a = i % 10;
    if ((a == e) && (b == d)) {
        return true;
    }
    return false;
}

int main()
{
    int A, B, ans = 0;
    std::cin >> A >> B;
    for (int i = A; i <= B; i++) {
        if (kaibun(i) == true) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
}
