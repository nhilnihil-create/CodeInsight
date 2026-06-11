#include <bits/stdc++.h>
using namespace std;

int main(void){
    unsigned long long int X,Y,A;
    cin >> X >> Y;
     
    int count = 0;
    A = X;
    while(A<=Y){
        A *= 2;
        count++;
    }

    cout << count << endl;
    return 0;
}