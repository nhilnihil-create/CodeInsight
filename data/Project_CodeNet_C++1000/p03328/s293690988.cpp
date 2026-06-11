#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int a,b;
    cin >> a >> b;
    int d = b-a;
    int B = (d+1)*d/2;
    cout << B - b << endl;
}
