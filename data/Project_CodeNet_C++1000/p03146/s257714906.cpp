#include <iostream>
#include <vector>


int main(void){
    int s, ans, cnt=1;
    std::cin >> s;
    std::vector<std::vector<int>> d(1000001, std::vector<int>(2, 0));
    ++d.at(s).at(1);

    while (true){
        ++cnt;
        if (s % 2 == 0) s /= 2;
        else s = 3 * s + 1;
        if (d.at(s).at(1) == 1) break;
        ++d.at(s).at(1);
    }

    std::cout << cnt << std::endl;

    return 0;
}
