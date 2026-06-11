#include <bits/stdc++.h>
using namespace std;
 
int main() {int s;
    cin >> s;
    int hundred = s / 100;
    int ten = (s - hundred * 100) /10;
    int one = (s - hundred * 100 - ten * 10);
    cout << hundred + ten + one << endl;
}