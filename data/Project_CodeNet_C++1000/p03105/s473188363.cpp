#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
#define pi 3.1415926

int a[3];

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int br=0;
    if(b/a > c)
        cout << c;
    else 
        cout << b/a;
}
	
