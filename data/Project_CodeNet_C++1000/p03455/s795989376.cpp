#include<iostream>
using namespace std;

int main(){
    int number1,number2;
    cin >> number1 >> number2;
    if((number1*number2) % 2 == 0) {
        cout << "Even" << endl;
    } else {
        cout << "Odd" <<endl;
    }
    return 0;
}