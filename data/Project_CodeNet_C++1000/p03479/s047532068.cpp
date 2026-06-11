#include <iostream>
using namespace std;

long long X,Y, total, bil;

int main() {
    cin >> X >> Y;;
    bil = X;
    while(bil <= Y){
       bil *= 2;
       total++;
    }
    cout << total << endl;
}