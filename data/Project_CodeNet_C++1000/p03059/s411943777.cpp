#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,T;
    cin >>A>>B>>T;

    long ans = T/A*B;
    cout << ans << endl;
}