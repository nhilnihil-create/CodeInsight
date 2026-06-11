#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int left = a + b;
    int right = c + d;
    string lr = "";
    if (left > right){
        lr = "Left";
    } else if (left == right){
        lr = "Balanced";
    } else {
        lr = "Right";
    }
    cout << lr << endl;
}