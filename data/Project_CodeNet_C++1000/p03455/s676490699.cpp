#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int a,b;
    cin >> a >> b;
    cout << (((a*b)%2==0)?"Even":"Odd") << endl;
}