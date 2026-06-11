#include <bits/stdc++.h>
using namespace std;

int main(){
    long r, d, x2000;
    cin >> r >> d >> x2000;
    
    long prev = x2000;
    for (int i = 0; i < 10; i++) {
        long buf = r * prev - d;
        cout << buf << endl;
        prev = buf;
    }
}
