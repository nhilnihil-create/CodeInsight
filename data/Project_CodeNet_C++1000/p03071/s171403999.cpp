#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, point = 0;
    cin >> A >> B;
    if (A > B) point += A--;
    else point += B--;
    if (A > B) point += A--;
    else point += B--;
    cout << point << endl;
    return 0;
}