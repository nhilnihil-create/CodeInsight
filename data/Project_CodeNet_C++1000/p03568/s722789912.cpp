#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    
    long long int N;
    long long int total;
    long long int odd_pattern = 1;
    
    cin >> N;
    long long int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x % 2 == 0)
            odd_pattern *= 2;
    }
    total = pow(3,N);
    
    cout << total - odd_pattern << endl;
    
    return 0;
}