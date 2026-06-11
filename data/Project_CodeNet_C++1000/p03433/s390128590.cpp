#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, A;
    cin >> N >> A;
    N %= 500;
    if (N <= A) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
