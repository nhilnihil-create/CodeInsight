#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int minab = min(a,b);
    int maxab = max(a,b);
    if(minab < c && c < maxab){
        cout << "Yes";
    } else {
        cout << "No";
    }
}