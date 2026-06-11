#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    int N, T, A;
    cin >> N >> T >> A;
    
    int current_closest = 99999999;
    int best_candidate = 999999;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        int temp = (T*1000-x*6)-A*1000;
        if (temp < 0) temp = -(temp);
        if (temp < current_closest) {
            current_closest = temp;
            best_candidate = i;
        }
        
    }
    
    cout << best_candidate << endl;
    
    return 0;
}