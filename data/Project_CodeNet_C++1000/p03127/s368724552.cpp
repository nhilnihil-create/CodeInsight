#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::cin >> a[0];
    int g = a[0];
    for(int i = 1; i < n; i++){
        std::cin >> a[i];
        g = gcd(g, a[i]);
    }

    std::cout << g << std::endl;

    
    return 0;
}
