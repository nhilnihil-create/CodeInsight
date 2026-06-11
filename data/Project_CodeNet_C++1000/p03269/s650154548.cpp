#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

int n; 

int main() {
    int l; 
    scanf("%d", &l); 
    
    while ((1 << n) <= l) n++; 
    
    std::vector<std::pair<std::pair<int, int>, int> > v;
    std::vector<std::pair<std::pair<int, int>, int> >::iterator it; 
    for (int i = 0; i < n - 1; i++) {
        v.push_back({{i, i + 1}, 0});
        v.push_back({{i, i + 1}, 1 << i}); 
    }

    for (int i = n - 2; i >= 0; i--) {
        if (1 << (n - 1) <= l - (1 << i)) {
            v.push_back({{i, n - 1}, l - (1 << i)}); 
            l -= (1 << i); 
        }
    }

    printf("%d %d\n", n, v.size()); 

    for (it = v.begin(); it != v.end(); it++) {
        printf("%d %d %d\n", it->first.first + 1, it->first.second + 1, it->second); 
    }

    return 0; 
}