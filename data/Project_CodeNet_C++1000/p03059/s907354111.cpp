#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int a, b, t;
    cin >>a >> b >>t;
    int res = (t / a) * b;
    cout << res;
}