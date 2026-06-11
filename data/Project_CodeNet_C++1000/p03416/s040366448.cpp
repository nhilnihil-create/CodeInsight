#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, count = 0, x, x1, x2, x4, x5;
    cin >> A >> B;
    for(int i = A; i <= B; i++){
        x = i;
        x1 = x % 10;
        x /= 10;
        x2 = x % 10;
        x /= 100;
        x4 = x % 10;
        x /= 10;
        x5 = x % 10;
        if(x1 == x5 && x2 == x4) count++;
    }
    cout << count << endl;
}