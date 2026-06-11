#include <bits/stdc++.h>
using namespace std;

int main(){

    int D, N;
    cin >> D >> N;
    vector<int> A(N);
    int ans = 0;

    if (N != 100){    
        if (D == 0) ans = 1*N;
        else if (D == 1) ans = 100*N;
        else ans = 10000*N;
    }
    else {
        if (D == 0) ans = 101;
        else if (D == 1) ans = 100*(99+2);
        else ans = 10000*(99+2);
    } 

    cout << ans << endl;
    return 0;
}