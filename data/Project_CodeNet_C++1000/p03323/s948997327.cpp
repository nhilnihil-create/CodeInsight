#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    cout << ((16 - a - b)/2 >= abs(a-b) ? "Yay!" : ":(");
    return 0;
}

