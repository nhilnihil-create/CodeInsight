#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int plan1_fee = a * n;
    int plan2_fee = b;
    cout << min(plan1_fee, plan2_fee) <<endl;
}