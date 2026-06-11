#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a+b == c+d){
        cout << "Balanced" << endl;
    }
    else if (a+b > c+d){
        cout << "Left" << endl;
    }
    else { 
        cout << "Right" << endl;
    }
}