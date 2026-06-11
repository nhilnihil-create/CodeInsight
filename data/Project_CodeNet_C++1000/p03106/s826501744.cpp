#include <iostream>
#include <stack>
using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    if (A < B)
    {
        int temp = A;
        A = B;
        B = temp;
    }
    int r = A % B;
    while (r != 0)
    {
        A = B;
        B = r;
        r = A % B;
    }
    stack<int> fgc;
    for (int i = 1; i <= B; i++)
    {
        if (B % i == 0) fgc.push(i);
    }
    for (int i = 0; i < K - 1; i++) fgc.pop();
    cout << fgc.top();
}