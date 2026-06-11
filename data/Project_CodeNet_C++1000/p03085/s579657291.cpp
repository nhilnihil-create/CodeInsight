#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
#define pi 3.1415926

int a[3];

int main(){
    char a;
    cin >> a;
    if(a == 'A')
        cout << "T";
    else if(a == 'C')
        cout << "G";
    else if(a == 'T')
        cout << "A";
    else if(a == 'G')
        cout << "C";
}
	
