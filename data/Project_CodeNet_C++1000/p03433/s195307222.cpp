#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, x;
    cin >> a >> x;
    int amari = a % 500;
    if(amari > x) cout << "No" << endl;
    else cout << "Yes" << endl;
}
