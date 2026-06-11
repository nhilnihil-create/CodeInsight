#include<bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++)std::cin >> a[i];
    double ave = std::accumulate(a.begin(),a.end(),0.0) / (double)n;
    double min = 10000000;
    int itr;
    for(int i = n - 1; i >= 0; i--){
        if(std::abs(a[i] - ave) <= min){
            min = std::abs(a[i] - ave);
            itr = i;
        }
    }
    std::cout << itr << std::endl;
}