#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A, B, sum = 0;
    cin >> A >> B;
    for (int num = A; num < B+1; num++){
        
        int reverse = 0;
        int a = num;
        for (int i = 0; i < 5; i++){
            int remaind = 0;
            remaind = a % 10;
            reverse = reverse * 10 + remaind;
            a /= 10;
        }

        if (num == reverse) sum++;
        
    }
    
    cout << sum << endl;
}