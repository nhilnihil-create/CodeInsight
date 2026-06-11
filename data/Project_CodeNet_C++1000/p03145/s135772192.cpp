#include <bits/stdc++.h>

using namespace std;


int main() {

    int a, b, c, res;
    cin >> a >> b >> c;

    if(a < c && b < c){

        cout << (a*b)/2 << '\n';

    }
    else if (a< b && c < b) {

        cout << (a*c)/2 << '\n';

    }
    else if (b < a && c <a ) {

        cout << (b*c)/2 << '\n';

    }

    return 0;
}

