#include <iostream>
#include <vector>


int main(void){
    int s, ans, cnt=1;
    std::cin >> s;
    std::vector<int> d(1000001, 0);
    ++d.at(s);

    while (true){
        ++cnt;
        if (s % 2 == 0) s /= 2;
        else s = 3 * s + 1;
        if (d.at(s) == 1) break;
        ++d.at(s);
    }

    std::cout << cnt << std::endl;

    return 0;
}
