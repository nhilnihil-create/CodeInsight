#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    int c = a*b;

    if(c % 2 == 0)
        cout << "Even" << endl;
    if(c % 2 == 1)
        cout << "Odd" << endl;

    return 0;
}