#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int A, B, K;
    cin >> A >> B >> K;
    for (int i = 0; i < K; i++){
        if (i % 2 == 0){
            A /= 2;
            B += A;
        }
        else {
            B /= 2;
            A += B;
        }
    }
    cout << A << " " << B << endl;
}

