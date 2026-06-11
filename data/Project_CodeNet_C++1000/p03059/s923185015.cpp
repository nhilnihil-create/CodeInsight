#include <iostream>

using namespace std;

int main() {
    int a, b;
    float t;
    int tmp = 1;
    int result;

    cin >> a >> b >> t;

    while(1) {

        if(tmp % a == 0) {
            result += b;
        }

        tmp ++;

        if(tmp > t+0.5) {
            break;
        }
    }

    cout << result << endl;
    
}