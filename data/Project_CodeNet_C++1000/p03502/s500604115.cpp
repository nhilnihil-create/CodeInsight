#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, numerator, denominator = 0;
    cin >> N;
    numerator = N;
    for(int i = 8; i >= 0; i--){
        int number = 0;
        number = N / std::pow(10, i);
        denominator += number;
        N -= number * std::pow(10, i);
    }
    if((numerator % denominator) == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
