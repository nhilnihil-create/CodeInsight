#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;

int main(void) {
    int n; cin >> n;
    string N = to_string(n);
    string answer = "";
    for (int i=0; i<3; i++) {
        if (N[i] == '1') {
            answer = answer + "9";
        } else if(N[i] == '9') {
            answer = answer + "1";
        }
    }
    cout << answer << endl;
}