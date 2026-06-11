#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;

int main(void) {
    int a,b,t; cin >> a >> b >> t;
    int i = 1;
    int sum = 0;
    while (i <= t) {
        if (i % a == 0) {
            sum = sum + b;
        }
        i++;
    }
    cout << sum << endl;
}