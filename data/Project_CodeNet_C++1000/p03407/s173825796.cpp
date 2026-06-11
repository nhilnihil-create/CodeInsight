#include <iostream>

using namespace std;

int main(){
int A, B, C;
    cin >> A >> B >> C;
    if (A + B < C) { cout << "No"; }
    else if (A + B >= C) {
        if (A + B == 1) { cout << "No"; }
        else
            cout << "Yes";
    }
    

    return 0;
}