#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main() {
    int a, b;
    cin >> a >> b;
    if(b%a == 0){
        cout << a+b << endl;
    }
    else {
        cout << b-a << endl;
    }
}