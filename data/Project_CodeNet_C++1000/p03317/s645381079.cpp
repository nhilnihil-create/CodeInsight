#include <bits/stdc++.h>
using namespace std;
int main() {
    double N, K;
    cin >> N >> K;
    int count = 1;
    N -= K;
    count += (ceil)(N/(K-1));
    cout << count << endl;
}