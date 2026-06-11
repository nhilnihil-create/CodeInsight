//
//  755.cpp
//  my_programs
//
//  Created by Jiatuo Zou on 9/16/20.
//  Copyright © 2020 Jiatuo Zou. All rights reserved.
//

#include <iostream>

using namespace std;

int Search(int n, int digits, int hasNumber[], int d, int numbers[], int sum, int value){
    if(d == digits){
        for(int i = 0; i < 3; i++){
            if(hasNumber[i] == 0){
                return 0;
            }
        }
        if(value > n){
            return 0;
        }
        return 1;
    }
    for(int i = 0; i < 3; i++){
        hasNumber[i]++;
        int x = numbers[i];
        for(int j = d; j < digits - 1; j++){
            x *= 10;
        }
        value += x;
        sum += Search(n, digits, hasNumber, d + 1, numbers, 0, value);
        value -= x;
        hasNumber[i]--;
    }
    return sum;
}

int main()
{
    int n, numbers[3] = {3, 5, 7}, digits = 0, hasNumber[3] = {0}, ans = 0;
    cin >> n;
    int f = n;
    while(n > 0){
        digits++;
        n /= 10;
    }
    for(int i = 3; i <= digits; i++){
        ans += Search(f, i, hasNumber, 0, numbers, 0, 0);
    }
    cout << ans << endl;
    return 0;
}
