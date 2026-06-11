#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, K;
    cin >> A >> B >> K;
    int count = 0;
    while(true) {
        B += A / 2;
        A /= 2;
        count++;
        if(count == K) break;
        A += B / 2;
        B /= 2;
        count++;
        if(count == K) break;
    }
    cout << A << " " << B << endl;
}