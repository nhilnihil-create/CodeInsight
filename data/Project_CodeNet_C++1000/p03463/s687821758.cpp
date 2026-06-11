#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    if((b - a - 1) == 0) {
        cout << "Borys" << endl;
        return 0;
    }

    if((b - a - 1) % 2) cout << "Alice" << endl;
    else cout << "Borys" << endl;
    return 0;
}