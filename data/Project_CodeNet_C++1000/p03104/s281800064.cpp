#include <iostream>

using namespace std;

long long  XORsum(long long a)
{
    // long long x;
    // switch (a % 4)
    // {
    // case 0:
    //     ans = a;
    //     break;
    
    // case 1:
    //     ans = 1;
    //     break;

    // case 2:
    //     ans = 1 + a;
    //     break;

    // case 3:
    //     ans = 0;
    //     break;
    // }
    if (a % 4 == 0) return a;
    if (a % 4 == 1) return 1;
    if (a % 4 == 2) return 1 ^ a;
    if (a % 4 == 3) return 0;

}

int main(int argc, char const *argv[])
{
    long long A, B;
    cin >> A >> B;
    A--;
    long long sumA = XORsum(A);
    long long sumB = XORsum(B);

    cout << (XORsum(B) ^ XORsum(A)) << endl;

    return 0;
}