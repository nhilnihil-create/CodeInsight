#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int N; cin >> N;
    int i = 1;
    int counter = 0;
    while (i <= N) {
        if ((i) % 2 == 0) {
            i++;
            continue;
        } 
        int localCouter = 0;
        for (int j = 1; j <= N; j++) {
           if (i % j == 0) localCouter++;
        }
        if (localCouter == 8) counter++;
        i++;
    }
    cout << counter << endl;

}
