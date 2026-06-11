#include <iostream>  
#include <string.h> 
using namespace std;
int main() {
    string x, y;
    cin >> x >> y;
    for (int i = 0, j = 2; i < 3; i++, j--) {
        if (x[i] != y[j]) {
            cout << "NO";
            return 0;
        }

    }cout << "YES";

    
    return 0;
}

