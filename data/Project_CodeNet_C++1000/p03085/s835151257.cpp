#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;

int main(void) {
    string n; cin >> n;
    if (n == "A") {
        cout << 'T' << endl;
    } else if (n == "T") {
        cout << 'A' << endl;
    } else if (n == "G") {
        cout << 'C' << endl;
    } else {
        cout << 'G' << endl;
    }
}
