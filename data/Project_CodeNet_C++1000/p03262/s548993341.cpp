#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;

int main(void) {
    int n,X; cin >> n >> X;
    vector<int> x(n);
    vector<int> tmp(n);
    int i = 0;
    int min = pow(10,9);
    while (i < n) {
        cin >> tmp[i];
        x[i] = abs(tmp[i] - X);
        if (x[i] < min) min = x[i];
        i++;
    }
    i = min;
    int D = 0;
    while (i > 0) {
        int flag = 1;
        int j = 0;
        while (j < n) {
            if (x[j] % i != 0) {
                flag = 0;
                break;
            } 
            j++;
        }
        if (flag) {
            D = i;
            break;
        } 
        i--;
    }
    cout << D << endl;
}