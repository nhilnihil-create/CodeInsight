#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;

int main(void) {
    int A,B; cin >> A >> B;
    string ans = "No";
    int i = 1;
    while (i < 4) {
        if ((A * B * i) % 2 == 1) ans = "Yes";
        i++;
    }
    cout << ans << endl;
}

