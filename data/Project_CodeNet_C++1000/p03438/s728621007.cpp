#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

long long n;

int main() {
    cin >> n;
    vector<long long> a(n, 0);
    vector<long long> b(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> a.at(i);
    }
    for(int i = 0; i < n; ++i) {
        cin >> b.at(i);
    }

    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        if(a.at(i) > b.at(i)) {
            sum += 2*(a.at(i)-b.at(i));
            b.at(i) = a.at(i);
        }
    }

    for(int i = 0; i < n; ++i) {
        if(a.at(i) < b.at(i)) {
            long long ccc = (b.at(i)-a.at(i))/2;
            sum -= ccc*2;
        }
    }

    if(sum <= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}