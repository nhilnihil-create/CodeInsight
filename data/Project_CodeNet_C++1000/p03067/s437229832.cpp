#include <bits/stdc++.h>

signed main(){
    int a,b,c;
    std::cin >> a >> b >> c;
    if (std::min(a,b) > c || std::max(a,b) < c)
        std::cout << "No\n";
    else
        std::cout << "Yes\n";
    return 0;
}