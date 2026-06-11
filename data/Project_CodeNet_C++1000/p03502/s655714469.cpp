#include <bits/stdc++.h>
using namespace std;

int main(){
    int number;
    cin >> number;
    int digit = 10;
    int divider = number % digit;
    for (int i = 0; i<7; i++){
        if(number / digit)divider += (number % (digit*10))/digit;
        digit *= 10;
    }
    if(number%divider == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}