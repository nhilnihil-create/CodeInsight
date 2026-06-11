#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

vector<bool> primeno(100010, true);
void Eratosthenes(int N) {
    primeno.at(0) = primeno.at(1) = false;
    int limit = sqrt(N);
    for(int i = 2; i < limit; ++i) {
        if(primeno.at(i)) {
            for(int j = 0; i*(j+2) < N; ++j) {
                primeno.at(i*(j+2)) = false;
            }
        }
    }
}

int MAX = 100000;

int main() {
    int n; cin >> n;
    Eratosthenes(MAX);
    vector<int> A(n, 0);
    int now = 0;
    for(int i = 0; i <= 55555; ++i) {
        if(primeno.at(i)) {
            if((i%5)==1) {
                A.at(now) = i;
                now++;
            }
        }
        if(now == n) break;
    }

    for(int i = 0; i < n; ++i) {
        if(i == n-1) cout << A.at(i) << endl;
        else cout << A.at(i) << " ";
    }
}