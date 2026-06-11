#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
#define pi 3.1415926
 
int a[3];
 
int main(){
    int n;
    cin >> n;
    int j = n%10;
    int d = (n % 100)/10;
    int s = n/100;
    if(j == 9)
        j = 1;
    else
        j = 9;
    if(d == 9)
        d = 1;
    else
        d = 9;
    if(s == 9)
        s = 1;
    else
        s = 9;
    cout << s << d << j;
}