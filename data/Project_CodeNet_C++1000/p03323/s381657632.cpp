#include <iostream>
using namespace std;

int main() {
    long long int a, b;
    cin >> a >> b;
    if(a - b > 1 || b - a > 1){
        cout << ":(" << endl;
    }
    else{
        cout << "Yay!" << endl;
    }
}