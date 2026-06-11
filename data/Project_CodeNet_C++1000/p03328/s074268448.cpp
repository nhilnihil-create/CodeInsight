#include <bits/stdc++.h>
using namespace std;

int func(int n) {
    if (n == 0) {
        return 0;
    }
    return func(n-1) + n;
}

int main() 
{
    int A,B;
    cin >> A >> B;
    cout << func(B-A)-B << endl;
}