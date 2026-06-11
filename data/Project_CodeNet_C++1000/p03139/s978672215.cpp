#include<iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<stdio.h>
#define rep(i,n)for(int i=0;i<n;i++)
//printf("%.yf\n",x); xを小数点以下y桁で
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(b, c) << " ";
    if (b + c < a) {
        cout << 0 << endl;
    }
    else {
        cout << b + c - a << endl;
    }
    return 0;
}