#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int fd = n / 111;
    if(n % 111 != 0) fd++;
    cout << fd * 111 << endl;
    return 0;
}

