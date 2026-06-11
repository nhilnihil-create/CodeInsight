#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int A, B, C; cin >> A >> B >> C;
    int K; cin >> K;
    cout << A + B + C + max(max(A, B), C) * (pow(2, K) - 1) << endl;
}
