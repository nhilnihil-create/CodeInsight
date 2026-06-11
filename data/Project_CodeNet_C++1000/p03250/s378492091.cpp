#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
#define pi 3.1415926

int x[3];

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    x[0] = a;
    x[1] = b;
    x[2] = c;
    sort(x, x+3);
    cout << x[2]*10 + x[1] + x[0];
}
	
