#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const int Inf = 1e9;
const ll INF = 9223372036854775807;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ret = Inf;
    int w = 0;
    int b = 0;
    for(int i = 0;i < N;i++) {
        if(S.at(i) == '.') {
            w++;
        }
    }
    for(int i = 0;i < N;i++) {
        ret = min(ret,w + b);
        if(S.at(i) == '#') {
            b++;
        }
        else {
            w--;
        }
    }
    ret = min(ret,w + b);
    cout << ret << endl;
}