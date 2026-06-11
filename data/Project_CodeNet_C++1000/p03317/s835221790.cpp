#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    int count = 1;
    N -= K;
    count += (ceil)((double)N/(K-1));
    cout << count << endl;
}