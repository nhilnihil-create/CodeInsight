#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int a = num / 100;
    num = num % 100;
    int b = num / 10;
    int c = num % 10;

    cout << a+b+c << endl;
}