#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    string S;
    cin >> S;
    int min = 999;
    rep(i,S.size()-2) {
        int a = 100*(S[i] - '0') + 10*(S[i + 1] - '0') + (S[i + 2] - '0');
        if (abs(a - 753) < min) {
            min = abs(a - 753);
        }
        
    }
    cout << min << endl;
    
}

