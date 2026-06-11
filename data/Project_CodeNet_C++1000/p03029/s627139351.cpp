#include <iostream>
#include <string>
using namespace std;

int main (void){
    int a = 0;
    int p = 0;
    int ap = 0;
    cin >> a >> p;
    p += a * 3;
    ap += p / 2;
    cout << ap << endl;
    return 0;
}

