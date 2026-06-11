#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
#define pi 3.1415926

int x[3];

int main(){
    int r;
    cin >> r;
    if(r < 1200)
        cout << "ABC";
    else if(r < 2800)
        cout << "ARC";
    else
        cout << "AGC";
    
}
	
