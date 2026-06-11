//
//  main.cpp
//  C-snuke_the_wizard
//
//  Created by david chong on 8/21/19.
//  Copyright © 2019 david chong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// thanks Aram! <3 <3 <3
int elegantSolution(vector<char> & charVec, vector<char> & squareVec, vector<char> & dirVec) {
    
    char lhs, rhs, c, d, lastChar, lastD, myIdx;
    
    
    int leftIdx = 0;
    int rightIdx = charVec.size()-1;
    
    lhs = charVec.front();
    rhs = charVec.back();
    
    for(int i = squareVec.size()-1; i >= 0; i--) {
        c = squareVec[i];
        d = dirVec[i];
        
        if(c == charVec[leftIdx] && d == 'L') {
            leftIdx++;
        } else if(0 < leftIdx && charVec[leftIdx-1] == c && d == 'R') {
            leftIdx--;
        }
        
        if(c == charVec[rightIdx] && d == 'R') {
            rightIdx--;
        } else if( (rightIdx < charVec.size()-1) && charVec[rightIdx+1] == c && d == 'L') {
            rightIdx++;
        }
        
        if(leftIdx > rightIdx) {
            break;
        }
        
//        printf("%i:%i   %i\n", leftIdx, rightIdx, (rightIdx+1)-leftIdx);
    }
    
    //    printf("%i:%i \t %i \t %i\n", leftIdx, rightIdx, (rightIdx+1)-leftIdx, doubleHeadCount);
    
    //    printf("*** %i\n", charVec.size());
    
    
    int result = 0;
    
    if(rightIdx > leftIdx) {
        result = (rightIdx+1) - leftIdx;
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    //    freopen("input.in", "r", stdin);
//        freopen("test_03.txt", "r", stdin);
//        freopen("test_18.txt", "r", stdin);
    
    int n, q;
    
    string str;
    
    cin >> n >> q;
    
    vector<char> charVec(n);
    vector<char> squareVec(q);
    vector<char> dirVec(q);
    
    cin >> str;
    
    
    
    for(int i = 0; i < str.size(); i++) {
        charVec[i] = str[i];
    }
    
    
    //    cout << lhs << " " << rhs << endl;
    
    for(int j = 0; j < q; j++) {
        //        cin >> c >> d;
        //        printf("%c %c\n", c, d);
        cin >> squareVec[j] >> dirVec[j];
    }
    
    
    cout << elegantSolution(charVec, squareVec, dirVec) << endl;
    
    //    cout << solve(inVec, myMap, squareVec, dirVec, lhs, rhs) << endl;
    
    
    return 0;
}
