#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    string N;
    cin >> N;
    
    long long int dig_N = stoll(N);
    
    long long int power = 1;
    for (int i = 0; i < N.length() - 1; i++) {
        power *= 10;
    }

    if ((dig_N + 1) % power == 0){
        int total = 0;
        for (int i = 0; N[i]; i++)
            total += (N[i] - '0');
        cout << total << endl;
        return 0;
    }
    
    
    if (dig_N == N.length() * 10 -1) {
        int total = 0;
        for (int i = 0; i < N.length(); i++) {
            total += (N[i] - '0');
        }
        cout << total;
        return 0;
    }
    
    long long int first_dig = (N[0] - '0') - 1;
    cout << (N.length() - 1) * 9  + first_dig<< endl;
    
    return 0;
}