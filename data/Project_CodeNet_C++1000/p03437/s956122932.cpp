//
//  main.cpp
//  A - Two Integers
//
//  Created by Anson Thai on 11/4/20.
//  Copyright © 2020 Anson Thai. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    int x, y;
    
    std::cin >> x;
    std::cin >> y;
    
    int m = 2;
    
    if (x%y == 0)  {
        std::cout << -1 << std::endl;
        return 0;
    }
    
    
    int test = m*x;
    int test2 = (10^18)/x;
    int test3 = x*y;
    while ((m)<=(y*2)) {
        if (((m*x)%y) == 0) {
            m++;
        } else {
            std::cout << m*x << std::endl;
            return 0;
            
        }
    }
    
    std::cout << -1 << std::endl;
    
    
    return 0;
}
