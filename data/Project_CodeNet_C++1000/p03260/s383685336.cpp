#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    bool odd = false;
    int d = a*b;
    if(d*1 % 2 != 0 || d*3 % 2 !=0 || d*2 % 2 != 0) odd = true;
    if(odd) cout << "Yes" << endl;
    else cout << "No" << endl;
}