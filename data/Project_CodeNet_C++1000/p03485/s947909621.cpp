#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    int b;
    double tmp;
    cin >> a >> b;
    tmp = double(a + b) / 2;
    //cout << tmp << endl;
    cout << (int)ceil(tmp) << endl;
}