#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int64_t A, B, C, K;
    cin >> A >> B >> C >> K;
    int64_t sa = A-B;
    if(K%2) sa *= -1;
    cout << sa << endl;
}   