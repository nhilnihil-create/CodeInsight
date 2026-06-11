#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, temp;
    cin >> N;

    temp = N;

    int f = 0;
    while(temp != 0){
        f += temp % 10;
        temp /= 10;
    }

    if((N % f) == 0) cout << "Yes" << endl;
    else             cout << "No"  << endl;
}
