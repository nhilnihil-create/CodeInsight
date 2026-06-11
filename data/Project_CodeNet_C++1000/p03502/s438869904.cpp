#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N, a, b, c, d, e, f, g, h, i;
    
    cin >> N;
    a = N % 10;
    b = N % 100 / 10;
    c = N % 1000 / 100;
    d = N % 10000 / 1000;
    e = N % 100000 / 10000;
    f = N % 1000000 / 100000;
    g = N % 10000000 / 1000000;
    h = N % 100000000 / 10000000;
    i = N % 1000000000 / 100000000;
    
    int ans = a+ b+ c+ d+ e+ f+ g+ h+ i;
    
    if(N % ans == 0)
    cout << "Yes" << endl;
    
    else
    cout << "No" << endl;
}
