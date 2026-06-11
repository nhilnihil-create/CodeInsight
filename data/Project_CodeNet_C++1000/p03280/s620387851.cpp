#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;

int main(void)
{
    int A, B;
    cin >> A >> B;

    int whole = A * B;
    cout << whole - (A + B - 1) << endl;
    return (0);
}