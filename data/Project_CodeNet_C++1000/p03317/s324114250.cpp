#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    int count = 1;
    N -= K;
    while(N > 0) N -= (K-1),count++;
    cout << count << endl;
}