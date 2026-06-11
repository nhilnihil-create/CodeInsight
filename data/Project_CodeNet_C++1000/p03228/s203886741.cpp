
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long A,B,K;
    cin >> A >> B >> K;
    for(int i = 1; i <= K; i++) {
        int X = A;
        int Y = B;
        if(i%2 == 0){
            B/=2;
            A+=Y/2;
        }
        else {
            A/=2;
            B+=X/2;
        }
    }
    cout << A << " " << B << endl;
}