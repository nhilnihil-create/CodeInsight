#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    string S;
    cin >> S;
    if(S.size() == 2) {
        cout << S << endl;
    }
    else {
        reverse(S.begin(),S.end());
        cout << S << endl;
    }
}