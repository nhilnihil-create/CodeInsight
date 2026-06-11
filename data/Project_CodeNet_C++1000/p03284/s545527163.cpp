#include<bits/stdc++.h>
using ll = long long;
const int INF_INT = 100000000;
const ll INF_LL = 1000000000000;
#define fir first
#define sec second


int main()
{
    int n,k;
    std::cin >> n >> k;
    std::cout << ((n + k - 1) / k) - (n / k) << std::endl;
}
