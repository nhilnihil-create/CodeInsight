#include <bits/stdc++.h>
using namespace std;

int main(){
    int s, c = 0;
    cin >> s;
    c = c + (s % 10);
    s = s / 10;
    c = c + (s % 10);
    s = s / 10;
    c = c + (s % 10);
    cout << c << endl;
}