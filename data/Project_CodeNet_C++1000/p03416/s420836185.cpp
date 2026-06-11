#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int n = 0;
    for(int i = A; i <= B; i++){
        int x4, x3, x1, x0;
        int i0 = i;
        x0 = i0 % 10;
        i0 /= 10;
        x1 = i0 % 10;
        i0 /= 100;
        x3 = i0 % 10;
        i0 /= 10;
        x4 = i0 % 10;
        if(x0 == x4 && x1 == x3){
            n++;
        }
    }
    cout << n << endl;
}