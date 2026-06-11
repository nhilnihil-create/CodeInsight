#include <iostream>

int main()
{
    long long int x,r,d;
    std::cin>>r>>d>>x;
    for (int i=0; i<10; i++)
    {
        long long int tmp=x*r-d;
        x=tmp;
        std::cout<<x<<"\n";
    }
    return 0;
}