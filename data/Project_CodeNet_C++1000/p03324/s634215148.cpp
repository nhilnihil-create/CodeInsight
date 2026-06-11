#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(void){
    int l, i=0, a[10], answer;
    while(2 > i){
        cin >> a[i];
        i++;
    }
    if (a[1] == 100) {
        answer = (std::pow(100, a[0]) * (a[1] + 1));
    } else {
        answer = (std::pow(100, a[0]) * a[1]);
    }
    cout << to_string(answer) << endl;
}