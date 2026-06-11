#include <bits/stdc++.h>
using namespace std; 
int main() {
    int a, b, c; 
    cin >> a >> b >> c; 

    int area = a * b * c / max ({a, b, c});
    cout << area / 2 << endl; 
}