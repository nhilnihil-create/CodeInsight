#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int max = 0;
    rep(i,N - 1) {
        int count = 0;
        vector<int> A(26,0);
        vector<int> B(26,0);
        string a = S.substr(0,i + 1);
        string b = S.substr(i + 1);
        rep(j,a.size()) {
            A[a[j] - 'a']++;
        }
        rep(k,b.size()) {
            B[b[k] - 'a']++;
        }
        rep(l,26) {
            if (A[l] > 0 && B[l] > 0) {
                count++;
            }
        }
        if (count > max) {
            max = count;
        }
    }
    cout << max << endl;
}

