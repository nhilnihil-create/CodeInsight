#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main() {
    int N,M; cin >> N >> M;
    int T = 1900*M+(N-M)*100;
    int ans = T*pow(2,M);
    cout << ans << endl;
}

