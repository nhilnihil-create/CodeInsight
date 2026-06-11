#include <iostream>
using namespace std;

int main() {
    int a,b,c,d,e,k;
    bool flag = 1;
    cin >> a >> b >> c >> d >> e >> k;
    if(abs(a - b) > k)flag = 0;
    if(abs(a - d) > k)flag = 0;
    if(abs(a - e) > k)flag = 0;
    if(abs(b - c) > k)flag = 0;
    if(abs(b - d) > k)flag = 0;
    if(abs(b - e) > k)flag = 0;
    if(abs(c - d) > k)flag = 0;
    if(abs(c - e) > k)flag = 0;
    if(abs(d - e) > k)flag = 0;
    if(flag)cout << "Yay!" << endl;
    else cout << ":(" << endl;
}