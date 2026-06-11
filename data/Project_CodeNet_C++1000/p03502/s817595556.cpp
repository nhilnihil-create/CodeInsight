#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin >> input;
    int sum_of_input = 0;
    for (char i : input){
        sum_of_input += i - '0';
    }
    if (stoi(input) % sum_of_input == 0){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}
