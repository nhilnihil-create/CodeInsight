//
//  AAAAAB.cpp
//  my_programs
//
//  Created by Jiatuo Zou on 7/22/20.
//  Copyright © 2020 Jiatuo Zou. All rights reserved.
//

#include <iostream>

int sum = 0;

void switchState(int n, int m, int d, int s[10][10], int k[10], int p[10], int states[10], int number){
    if(d == n){
        for(int i = 0; i < m; i++){
            number = 0;
            for(int j = 0; j < k[i]; j++){
                if(states[s[i][j] - 1] == 1){
                    number++;
                }
            }
            if(number % 2 != p[i]){
                return;
            }
        }
        sum++;
        return;
    }
    for(int i = 0; i <= 1; i++){
        states[d] = i;
        switchState(n, m, d + 1, s, k, p, states, number);
    }
    return;
}

int main()
{
    using namespace std;
    
    int n, m, k[10], s[10][10], p[10], states[10] = {0};
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> k[i];
        for(int j = 0; j < k[i]; j++){
            cin >> s[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        cin >> p[i];
    }
    switchState(n, m, 0, s, k, p, states, 0);
    cout << sum << endl;
    return 0;
}
