#include <bits/stdc++.h>
using namespace std;

int main(){
    int firstNum, secondNum;
    cin >> firstNum >> secondNum;
    if ( (firstNum + secondNum) % 2 == 0){
        cout << (firstNum + secondNum) / 2 << endl;
    } else {
        cout << ((firstNum + secondNum) / 2) + 1 << endl;
    }
}