#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm>
using namespace std;
int main(void){
    string S; cin >> S;
    int i = 0;
    int a, b; a = 0; b = 0;
    while (i < S.size()) {
        if (i % 2 == 0) {
            if (S[i] == '0') {
                a++;
            }
        } else {
            if (S[i] == '1') {
                a++;
            }
        }
        i++;
    }
    i = 0;
    while (i < S.size()) {
        if (i % 2 == 0) {
            if (S[i] == '1') {
                b++;
            }
        } else {
            if (S[i] == '0') {
                b++;
            }
        }
        i++;
    }
    cout << min(a,b) << endl;
}
