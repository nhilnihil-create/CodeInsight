#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if(c >  a + b) cout << "No" << endl;
    if(c <= a + b) cout << "Yes" << endl;
    return 0;
}