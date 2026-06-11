#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000001;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    if((abs(A - B) <= D && abs(B - C) <= D) || abs(A - C) <= D) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}