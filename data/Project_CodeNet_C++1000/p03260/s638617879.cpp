#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    int A, B;
    cin >> A >> B;
    cout << (A * B % 2 == 0 ? "No" : "Yes") << endl;
}