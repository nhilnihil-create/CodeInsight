#include <iostream>


int main()
{
    long long n,m,l=0,r=0;
    std::cin>>n>>m;
    std::cin>>l>>r;
    for (int i=1; i<m; i++)
    {
        long long li,ri;
        std::cin>>li>>ri;
        if (li>l) l=li;
        if (ri<r) r=ri;
    }
    if (l>r) std::cout<<0;
    else std::cout<<r+1-l;
    return 0;
}
