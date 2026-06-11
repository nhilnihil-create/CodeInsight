#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    int64_t n, m;
    if (N < 3) n = N % 2;
        else n = N - 2;
    if (M < 3) m = M % 2;
        else m  = M - 2;
    cout << n * m << endl;
}