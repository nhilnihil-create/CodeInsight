#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    cout << min(A, B) << ' ';
    if(A + B < N) cout << 0 << endl;
    else if(A < B) cout << B - (N - A) << endl;
    else cout << A - (N - B) << endl; 
}