#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a, b;
    cin >> a >> b;
    int x = a*b % 2;
    if (x != 0) {
        cout << "Odd" << endl;
    }
    else cout << "Even" << endl;
}