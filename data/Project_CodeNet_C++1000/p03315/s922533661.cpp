#include <iostream>
#include <stdio.h>
#include <vector> 
using namespace std;

int main(void) {
    int answer = 0;
    char a[4];
    for (int i=0; i<4; i++) {
        cin >> a[i];
        if (a[i] == '+') {
            answer++;
        } else {
            answer--;
        }
    }
    cout << answer << endl;
}