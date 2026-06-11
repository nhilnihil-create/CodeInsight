#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int N,K;
    cin >> N >> K;
    if(N<K) cout << 0 << endl;
    else cout << N-K+1 << endl;
}