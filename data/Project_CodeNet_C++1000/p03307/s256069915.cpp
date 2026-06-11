#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, res, i;
    cin >> n;

    while(i = n*2) {

        if(n%2 == 0){
            res = n;
            break;
        }

        else if(i%2 == 0 && i%n==0) {
            res = i;
            break;
        }
    }

    cout << res << '\n';

    return 0;
}

