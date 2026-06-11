#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    string S;
    cin >> S;
    int ans = 700;
    for(auto e:S) if(e == 'o') ans+=100;
    cout << ans << endl;
}
