//
//  main.cpp
//  TPC
//
//  Created by yuki on 2019/07/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>


using namespace std;

std::vector<int> range(int upper){
    std::vector<int> v(upper);
    std::iota (std::begin(v), std::end(v), 0);
    
    return v;
}

const unsigned char mostCommonChar(unsigned char a, unsigned char b, unsigned char c) {
    int _ac = 1;
    if (a == b) _ac += 1;
    if (a == c) _ac += 1;
    
    int _bc = 1;
    if (b == a) _bc += 1;
    if (b == c) _bc += 1;
    
    int _cc = 1;
    if (c == a) _cc += 1;
    if (c == b) _cc += 1;
    
    int m__max = std::max({_ac, _bc, _cc});
    
    if (m__max == _ac) {return a;}
    if (m__max == _bc) {return b;}
    if (m__max == _cc) {return c;}
    
    return -1;
}

const int difference(const std::string target, const std::string subject) {
    auto diffCounter = 0;
    for (const auto i: range(static_cast<int>(target.size()))) {
        if (target[i] != subject[i]) {
            diffCounter += 1;
        }
    }
    
    return diffCounter;
}

int main() {

    // ================================================ //
    int N;
    std::string A, B, C;
    
    cin >> N;
    cin >> A;
    cin >> B;
    cin >> C;
    
    auto mostCommonList = std::string();
    
    for (const auto i: range(N)) {
        mostCommonList += mostCommonChar(A[i], B[i], C[i]);
        
    }
    
    auto diff = difference(mostCommonList, A) + difference(mostCommonList, B) + difference(mostCommonList, C);
    
    cout << diff << endl;
}

