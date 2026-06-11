//
//  main.cpp
//  A-regular_triangle
//
//  Created by david chong on 8/21/19.
//  Copyright © 2019 david chong. All rights reserved.
//

#include <iostream>
#include <string>
#include <limits>

using namespace std;


string solve(int a, int b, int c) {
    
    string result = "No";
    if(a > 0 && a == b && b == c) {
        result = "Yes";
    }
    return result;
}


int main(int argc, const char * argv[]) {
    
//    freopen("input.in", "r", stdin);
    
    int a, b, c;
    
    cin >> a >> b >> c;
    
    cout << solve(a, b, c) << endl;
    
    
    return 0;
}
