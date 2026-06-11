#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main () {
    int n, T;
    std::cin >> n >> T;
    std::vector<int> c(n);
    std::vector<int> t(n);
    std::vector<int> cs;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> c[i];
        std::cin >> t[i];
        if (t[i] <= T)
        {
            cs.push_back(c[i]);
        }
    }
    
    if(cs.size() != 0) {
       std::cout << *std::min_element(cs.begin(), cs.end()) << "\n";
    } else {
        std::cout << "TLE" << std::endl;
    }
}