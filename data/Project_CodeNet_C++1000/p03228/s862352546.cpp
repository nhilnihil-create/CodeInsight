#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int A, B, K;

int main() {
    cin >> A >> B >> K;

    for (int i =0; i < K; i++){
        B += A/2;
        A = A/2;
        
        i++;
        if (i >= K) break;
        
        A += B/2;
        B = B/2;
    }

    cout << A << endl << B << endl;
    return 0;
}