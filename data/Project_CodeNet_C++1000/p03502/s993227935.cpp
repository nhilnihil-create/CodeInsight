#include <bits/stdc++.h>
using namespace std;

int main() {
    int input;
    cin >> input;
    int tmp = input, sum = 0;
    while(tmp > 0){
        sum += tmp % 10;
        tmp /= 10;
    }
    if (input % sum == 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
