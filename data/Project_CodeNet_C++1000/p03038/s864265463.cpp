#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool cmpPair(const std::pair<int, int> &l, const std::pair<int, int> &r)
{
    return l.second>r.second;
}

int main()
{
    typedef unsigned long long ull;
    ull n,m;
    std::cin>>n>>m;
    std::vector<ull> a(n);
    std::vector<std::pair<int,int> > c(m);
    for (int i=0; i<n; i++) std::cin>>a[i];
    std::vector<ull> tmp(n);
    for (ull i=0; i<m; i++)
        std::cin>>c[i].first>>c[i].second;
    std::sort(a.begin(),a.end());
    std::sort(c.begin(),c.end(),cmpPair);
    ull k=0;
    for (int i=0; i<m; i++)
    {
        while (c[i].second>a[k] && c[i].first)
        {
            if (c[i].second>a[k]) a[k++]=c[i].second;
            c[i].first--;
        }
    }
    ull s=0;
    for (int i=0; i<n; i++) s+=a[i];
    std::cout<<s;
    return 0;
}
