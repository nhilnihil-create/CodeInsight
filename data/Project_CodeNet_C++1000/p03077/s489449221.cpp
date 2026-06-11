#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num;
    long long a, b, c, d, e;
    long long numA = 0;
    long long numB = 0;
    long long numC = 0;
    long long numD = 0;
    long long numE = 0;
    long long cnt = 0;
    long long Min;

    cin >> num >> a >> b >> c >> d >> e;
    numA = num;

    Min = min(min(min(min(a, b), c), d), e);

    cnt = (num+Min-1) / Min + 4;
    cout << cnt;
}