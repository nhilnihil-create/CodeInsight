#include <bits/stdc++.h>

using namespace std;

int main(){

    int A, B, T, nb = 0, c = 0;

    cin >> A >> B >> T;

    c = A;
    while(c <= T){
        nb += B;
        c += A;
    }

    cout << nb << endl;

    return 0;

}
