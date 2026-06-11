#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
#define pi 3.1415926

int x[3];

int main(){
    int a, b;
    cin >> a >> b;
    int p = a * b;
    int cesta = 1*a + 1*b - 1*1;
    cout << p - cesta;
}
	
