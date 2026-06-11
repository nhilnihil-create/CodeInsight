#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    string s,t;
    cin >> s >> t;
    sort(all(s));
    sort(all(t));
    reverse(all(t));
    cout << ((s<t)?"Yes":"No") << endl;
}