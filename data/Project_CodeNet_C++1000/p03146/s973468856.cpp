#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
int main()
{
    long s;
    std::cin >> s;
    bool table[1000000+1]={};

    table[s]=1;
    long count=2;
    while(1){
        if(s%2==0){
            s=s/2;
        }else{
            s=3*s+1;
        }
        if(table[s]==1){
            break;
        }else{
            table[s]=1;
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}