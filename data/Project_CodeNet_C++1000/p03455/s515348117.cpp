#include <bits/stdc++.h>
using namespace std;

int main() {
    int firstNum, secondNum;
    cin >> firstNum >> secondNum;
    int multiplyTotal = firstNum * secondNum;

    if ((multiplyTotal % 2) == 0){
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl;
    }
}