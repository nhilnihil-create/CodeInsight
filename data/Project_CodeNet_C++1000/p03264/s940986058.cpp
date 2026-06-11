#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main (void){
    int k, n;
    int cont = 0;
    cin >> k;
    n = k * k;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 1){
            cont += 1;
        }
    }
    cout << cont / 2 << endl;
    return 0;
}
