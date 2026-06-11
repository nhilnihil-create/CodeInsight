#include <iostream>
#include <set>

int main()
{
    int s; std::cin >> s;
    std::set<int> ss;
    ss.insert(s);
    int cnt = 1;
    while (true) {

        // std::cout << s << std::endl;

        s = ((s%2) == 0)?(s/2):(3*s+1);
        cnt++;
        if (ss.find(s) != ss.end()) {
            break;
        }
        ss.insert(s);
    }

    std::cout << cnt << std::endl;

    return 0;
}
