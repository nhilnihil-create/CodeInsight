#include<bits/stdc++.h>
using ll = long long;
const ll INF = 1000000000000;

int main()
{
    int a,b;
    std::cin >> a >> b;
    std::cout << (b >= a ? a : a - 1) << std::endl;
}