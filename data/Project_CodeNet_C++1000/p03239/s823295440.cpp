#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int n, T; cin >> n >> T;
    long minC = 10e9;
    int i = 0;
    while (i < n) {
        int c,t;
        cin >> c >> t;
        if (t <= T) {
            if (minC > c) minC = c;
        }
        i++;
    }
    minC == 10e9 ? cout << "TLE" << endl : cout << minC << endl;
}