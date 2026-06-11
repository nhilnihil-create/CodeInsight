#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include<set>

int main()
{
    int n; std::cin >> n;
    std::vector<int> d(n);
    std::set<int> ds;
    for(int i = 0;i < n; i++) {
        std::cin >> d[i];
        ds.insert(d[i]);
    }

    std::cout << ds.size() << std::endl;
}

