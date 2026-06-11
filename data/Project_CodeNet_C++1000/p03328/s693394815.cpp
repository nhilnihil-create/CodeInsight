#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    
    int diff = b - a;
    
    int realb = (1 + diff) * diff / 2;
    
    cout << realb - b << endl;
    return 0;
}
