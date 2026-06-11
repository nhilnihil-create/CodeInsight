#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    int left = A+B;
    int right = C+D;
    string ans = "";
    if(left>right) ans = "Left";
    else if(left<right) ans = "Right";
    else ans = "Balanced";
    cout << ans << endl;
}