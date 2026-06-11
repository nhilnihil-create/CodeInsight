//
//  main.cpp
//  B-red_or_blue
//
//  Created by david chong on 8/21/19.
//  Copyright © 2019 david chong. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    
//    freopen("input.in", "r", stdin);
    
    int t;
    char c;
    
    map<char, int> myMap;
    
    cin >> t;
    
    while(t--) {
        cin >> c;
        myMap[c]++;
    }
    
    if(myMap['R'] > myMap['B']) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    
    return 0;
}
