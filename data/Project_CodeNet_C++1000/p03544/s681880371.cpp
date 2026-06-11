#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int64_t lucas(int64_t a, int64_t b, int n){
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return a + b;

    int64_t res = a + b;
    return lucas(b, res, n - 1);
}

int main(){
    int N;
    cin >> N;

    int64_t a = 2;
    int64_t b = 1;

    cout << lucas(a, b, N) << endl;    
}