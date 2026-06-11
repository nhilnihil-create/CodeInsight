#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#define ll long long
#define pi (acos(-1))
// https://atcoder.jp/contests/abc172/tasks/abc172_d
int main()
{   
    int s;
    std::cin >> s;
    int a, b;
    a = s / 100;
    b = s % 100;
   
    if (1 <= a && a <= 12)
    {
        if (1 <= b && b <= 12) { std::cout << "AMBIGUOUS" << std::endl; }
        else
        {   
            std::cout << "MMYY" << std::endl;
        }
    }
    else    
    {
        if (1 <= b && b <= 12) { std::cout << "YYMM" << std::endl; }
        else
        {
            std::cout << "NA" << std::endl;
        }
    }
    return 0;
}
