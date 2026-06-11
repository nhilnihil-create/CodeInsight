#include <iostream>
using namespace std;

long long n,x,hasil;

int main() {
    cin >> n >> x;
    while (n <=  x){
        hasil = hasil + 1;
        n = n*2;
    }
    cout << hasil;
}   
