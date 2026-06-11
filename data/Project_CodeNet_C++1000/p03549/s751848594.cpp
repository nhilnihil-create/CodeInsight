#include<iostream>
#include<vector>
#include<string>

int pow(int m){
    int ret = 1;
    while(m > 0){
        ret *= 2;
        m--;
    }
    return ret;
}

int main(){
    int n, m;
    std::cin >> n >> m;
    int base = 100 * (n - m);
    int r = pow(m);
    std::cout << (1900 * m + base) * r << std::endl;
    return 0;
}
