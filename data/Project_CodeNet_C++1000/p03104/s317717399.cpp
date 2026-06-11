#include <iostream>

using namespace std;

long long  XORsum(long long a)
{
    if(a == 0) return 0;

    long long ans;
    switch (a % 4)
    {
    case 0:
        ans = a;
        break;
    
    case 1:
        ans = 1;
        break;

    case 2:
        ans = 1 ^ a;
        break;

    case 3:
        ans = 0;
        break;
    }
    return ans;

}

int main(int argc, char const *argv[])
{
    long long A, B;
    cin >> A >> B;
    A--;
    long long sumA = XORsum(A);
    long long sumB = XORsum(B);

    cout << (sumB ^ sumA) << endl;

    return 0;
}