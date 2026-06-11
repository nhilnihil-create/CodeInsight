#include <iostream>
#include <string>
#include <map>

int main () {
    int n, m;
    std::cin >> n;
    std::string a[n];
    std::map<std::string, int> sc;
    
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
        sc.insert(std::make_pair(a[i], 0)); 
        sc[a[i]]++;  
    }
    std::cin >> m;
    std::string b[m];
    for(int i = 0; i < m; ++i){
        std::cin >> b[i];
        sc[b[i]] -= 1;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(ans < sc[a[i]]) ans = sc[a[i]];
    }
    std::cout << ans << std::endl;
}