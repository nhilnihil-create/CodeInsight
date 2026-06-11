#include <bits/stdc++.h>
using namespace std;

int sum_e_ord (int i) {
    int sum, temp;
    
    sum = 0;
    temp = i;
    for (int j = 0; j < 6 ; j++){
        sum += temp%10;
        temp = temp/10;
    }
    
    return sum;
}

int main() {
    int N, res, A, B;
    res = pow(10, 5);
    cin >> N;

    A = ceil(N/2);

    for (int i = 1; i <= A; i++){
        int A_d = sum_e_ord(i);
        int B_d = sum_e_ord(N-i);

        if (res > A_d + B_d){
            res = A_d + B_d;
        }
    }
    cout << res << endl;
}