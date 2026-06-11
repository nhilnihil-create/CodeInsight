#include <iostream>
#include <vector>
#include <algorithm>

int m(int m, int n)
{
    return std::min(m, n-m);
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i=0; i<n; i++) scanf(" %d", &a[i]);

    std::sort(a.begin(), a.end());
    int ai = a[n-1];
    int aj = a[0];
    for(int i=1; i<n-1; i++){
        if(m(aj, ai) < m(a[i], ai)) aj = a[i];
    }

    std::cout << ai << " " << aj << std::endl;
}