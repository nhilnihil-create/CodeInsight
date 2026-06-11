#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int n;
    cin >> n;

    int cpN = n;
    int digitSum = 0;
    while(cpN > 0) {
        digitSum += cpN % 10;
        cpN /= 10;
    }
    if (n % digitSum == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

}
