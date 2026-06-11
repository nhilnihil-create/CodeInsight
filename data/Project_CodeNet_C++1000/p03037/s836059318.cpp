#include<iostream>

int main(void){
    int n, m;
    std::cin >> n >> m;
    int lmax, rmin;
    lmax = 0;
    rmin = 1e9;
    for(int i = 0; i < m; i++){
        int l, r;
        std::cin >> l >> r;
        lmax = std::max(lmax, l);
        rmin = std::min(rmin, r);
    }
    if(lmax > rmin) std::cout << 0 << std::endl;
    else std::cout << rmin - lmax + 1<< std::endl;
    return 0;
}