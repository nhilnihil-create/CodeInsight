#include <bits/stdc++.h>
using namespace std;
int main() {
    int x; cin >> x;
    if(x%2 == 0){
        cout << x * x / 4 << endl;
    }
    else{
        cout << (x/2) * ((x+1)/2) << endl;
    }
}