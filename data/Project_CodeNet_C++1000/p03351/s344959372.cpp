#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (abs(b -a) <= d){
        if (abs(c - b) <= d){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (abs(c -a) <= d){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}