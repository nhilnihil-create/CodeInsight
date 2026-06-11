#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int mean = (a+b) / 2;
    int amari = (a+b) % 2;
    if(amari == 0) cout << mean << endl;
    else cout << mean + 1 << endl;
}