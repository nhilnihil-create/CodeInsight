#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a = 0;
    if( n <= 111) a = 111;
    else if( 111 < n && n <= 222) a = 222;
    else if( 222 < n && n <= 333) a = 333;
    else if( 333 < n && n <= 444) a = 444;
    else if( 444 < n && n <= 555) a = 555;
    else if( 555 < n && n <= 666) a = 666;
    else if( 666 < n && n <= 777) a = 777;
    else if( 777 < n && n <= 888) a = 888;
    else a = 999;

    cout << a << endl;
}